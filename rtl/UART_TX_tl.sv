//Test harness: wires baud_gen's tick output directly into UART_TX's tick input
//cocotb attaches to this module as the singular top-level DUT

//cocotb needs a singular testbench. Does not work the same as a '.sv' testbench file.

module UART_TX_tl(
    input logic clk, //shared system clock for both sub-modules
    input logic rst_n, //shared reset

    input logic[7:0] tx_data, //passthrough to UART_TX
    input logic tx_start, //passthrough to UART_TX
    output logic tx_busy, //passthrough to UART_TX
    output logic tx //passthrough to UART_TX
);

    logic tick; //internal wire - not a port, just connects the two instances

    //Instantiating UART_TX & baud_gen

    baud_gen #(
        .CLK_FREQ(50_000_000),
        .BAUD_RATE(9600)
    ) baud_gen_inst(
        .clk(clk),
        .rst_n(rst_n),
        .tick(tick) //drives internal wire above
    );

    //instance of UART_TX, consuming that tick
    UART_TX uart_tx_inst(
        .clk(clk),
        .rst_n(rst_n),
        .tick(tick), //fed from baud_gen_inst
        .tx_data(tx_data),
        .tx_start(tx_start),
        .tx_busy(tx_busy),
        .tx(tx)
    );

endmodule
