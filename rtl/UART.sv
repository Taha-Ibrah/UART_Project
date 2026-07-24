//Final top-level module for UART (buffered, with FIFOs)
//
//This module ties all building blocks into one complete, BUFFERED UART:
//   - baud_gen : generates the shared 16x-oversample "tick" that paces both
//                the transmitter and receiver (both agree on baud rate this way)
//   - FIFO (x2): decouple the producer/consumer from the slow serial line
//                  * TX FIFO: bytes the caller wants to send queue up here and
//                             drain out to UART_TX one at a time as it frees up
//                  * RX FIFO: bytes UART_RX assembles queue up here until the
//                             caller gets around to reading them
//   - UART_TX  : takes a parallel byte and shifts it out serially on 'tx'
//   - UART_RX  : watches the serial 'rx' line and reassembles a parallel byte
//
//Why the FIFOs matter: the serial line is slow (9600 baud). Without buffering,
//the caller would have to hand TX exactly one byte at a time and wait, and would
//have to grab each received byte instantly before the next overwrote it. The
//FIFOs let bursts of bytes queue on both sides so producer and consumer run on
//their own schedule.
//
//A single baud_gen is shared by BOTH the TX and RX paths. That's fine because
//TX and RX inside THIS chip run off the same system clock. (The "asynchronous"
//in UART refers to the lack of a shared clock between two SEPARATE devices, not
//between the TX/RX halves of one device.)

module UART(
    input  logic clk,   //system clock, drives every internal state machine
    input  logic rst_n, //active-low synchronous reset, shared by all submodules

    //--- Transmit side: caller PUSHES bytes into the TX queue ---
    input  logic [7:0] data_bus_in, //byte to enqueue for transmission
    input  logic       tx_wr_en,    //pulse high to push data_bus_in into the TX FIFO
    output logic       tx_full,     //1 = TX FIFO full, caller must wait before pushing

    //--- Receive side: caller POPS bytes out of the RX queue ---
    output logic [7:0] data_bus_out, //oldest unread received byte (valid when !rx_empty)
    input  logic       rx_rd_en,     //pulse high to pop/advance past data_bus_out
    output logic       rx_empty,     //1 = RX FIFO empty, nothing to read

    //--- Optional status/observability ---
    output logic rx_error, //pulses on a framing error (bad/missing stop bit)

    //--- Serial pins (the actual two UART wires) ---
    input  logic rx, //incoming serial line (from the other device's TX)
    output logic tx  //outgoing serial line (to the other device's RX)
);

    //Shared internal timing signal (not a port: nothing outside needs it).
    logic tick;

    //================================================================
    // Baud rate generator (shared by TX and RX)
    //================================================================
    // Produces 'tick' at 16x the baud rate. TX and RX each count 16 ticks per
    // bit; the 16x oversampling is what lets RX sample each bit near its midpoint.
    baud_gen #(
        .CLK_FREQ (50_000_000), //50MHz system clock
        .BAUD_RATE(9600)        //target line rate; both ends must agree on this
    ) baud_gen_inst (
        .clk  (clk),
        .rst_n(rst_n),
        .tick (tick)
    );

    //================================================================
    // TRANSMIT PATH:  data_bus_in -> TX FIFO -> UART_TX -> tx
    //================================================================

    // Wires between the TX FIFO and UART_TX.
    logic [7:0] tx_fifo_rd_data; //byte at the front of the TX queue
    logic       tx_fifo_empty;   //1 = TX queue has nothing waiting to send
    logic       tx_rd_en;        //glue-driven: pop one byte from the TX FIFO
    logic       tx_busy;         //from UART_TX: high while a byte is shifting out
    logic       tx_start;        //glue-driven: 1-cycle "begin sending" pulse

    // TX FIFO: the caller writes into it (data_bus_in / tx_wr_en / tx_full),
    // and the glue logic below drains it into UART_TX.
    FIFO #(
        .DATA_WIDTH(8),
        .DEPTH     (16)
    ) tx_fifo_inst (
        .clk    (clk),
        .rst_n  (rst_n),
        // write side = the external caller
        .wr_en  (tx_wr_en),
        .wr_data(data_bus_in),
        .full   (tx_full),
        // read side = drained internally into UART_TX
        .rd_en  (tx_rd_en),
        .rd_data(tx_fifo_rd_data),
        .empty  (tx_fifo_empty)
    );

    // ---- TX drain glue ----
    // Whenever the transmitter is free AND the queue has a byte waiting, pop one
    // byte and kick off a transmission. tx_start and tx_rd_en are asserted for
    // exactly one cycle so the FIFO advances once and UART_TX latches one byte.
    //
    // Timing note: FIFO's rd_data is combinational (mem[rd_ptr]), so on the SAME
    // cycle we pulse tx_rd_en the correct byte is already present on
    // tx_fifo_rd_data for UART_TX to latch. The FIFO advances rd_ptr on the next
    // edge, lining up the following byte for next time.
    assign tx_start = (!tx_busy) && (!tx_fifo_empty);
    assign tx_rd_en = tx_start; //pop exactly when we launch a transmission

    // UART_TX: shifts tx_fifo_rd_data out on 'tx' as a full UART frame.
    UART_TX uart_tx_inst (
        .clk     (clk),
        .rst_n   (rst_n),
        .tick    (tick),
        .tx_data (tx_fifo_rd_data), //byte at front of the TX queue
        .tx_start(tx_start),        //launch pulse from the glue logic
        .tx_busy (tx_busy),         //feeds back into the glue condition above
        .tx      (tx)               //serial output pin
    );

    //================================================================
    // RECEIVE PATH:  rx -> UART_RX -> RX FIFO -> data_bus_out
    //================================================================

    // Wires between UART_RX and the RX FIFO.
    logic [7:0] rx_byte;    //byte UART_RX just assembled
    logic       rx_done;    //1-cycle pulse: rx_byte is valid this cycle
    logic       rx_busy;    //high while a byte is being received (unused externally)
    logic       rx_fifo_full; //1 = RX queue full (an incoming byte would be dropped)

    // UART_RX: reassembles a byte from the serial 'rx' line.
    UART_RX uart_rx_inst (
        .clk     (clk),
        .rst_n   (rst_n),
        .tick    (tick),
        .rx      (rx),        //serial input pin
        .rx_byte (rx_byte),   //assembled byte -> pushed into the RX FIFO below
        .rx_done (rx_done),   //push strobe for the RX FIFO
        .rx_error(rx_error),  //framing-error pulse straight out to the caller
        .rx_busy (rx_busy)
    );

    // ---- RX capture glue ----
    // When UART_RX finishes a byte it pulses rx_done for one cycle; we use that
    // directly as the RX FIFO's write-enable so the freshly received byte is
    // pushed into the queue. If the RX FIFO happens to be full the byte is
    // dropped (FIFO ignores wr_en when full) — that's the standard overrun
    // behavior for an unread buffer.
    FIFO #(
        .DATA_WIDTH(8),
        .DEPTH     (16)
    ) rx_fifo_inst (
        .clk    (clk),
        .rst_n  (rst_n),
        // write side = fed internally by UART_RX
        .wr_en  (rx_done),
        .wr_data(rx_byte),
        .full   (rx_fifo_full),
        // read side = the external caller
        .rd_en  (rx_rd_en),
        .rd_data(data_bus_out),
        .empty  (rx_empty)
    );

endmodule
