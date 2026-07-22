//Test harness: wires baud_gen's tick output directly into UART_RX's tick input
//cocotb attaches to this module as the singular top-level DUT

//cocotb needs a singular testbench. Does not work the same as a '.sv' testbench file.

module UART_RX_tl(
    input logic clk, //shared system clock for both sub-modules
    input logic rst_n, //shared reset

    input logic rx, //passthrough to UART_RX

    output logic [7:0] rx_byte, //passthrough to UART_RX
    output logic rx_done, //passthrough to UART_RX
    output logic rx_error, //passthrough to UART_RX
    output logic rx_busy //passthrough to UART_RX
);

    logic tick; //internal wire - not a port, just connects the two instances

    //why is logic tick not an input/output logic?
    //input: something outside this module is expected to generature the baud timing. But since this module contains baud_gen,
    //this module takes care of it.
    //output: this means to expose an internal implementation detail to the outside world. Nothing external consumes it.


    //Instantiating UART_RX & baud_gen

    baud_gen #(
        .CLK_FREQ(50_000_000),
        .BAUD_RATE(9600)
    ) baud_gen_inst(
        .clk(clk),
        .rst_n(rst_n),
        .tick(tick) //drives internal wire above
    );

    //instance of UART_RX, consuming that tick
    UART_RX uart_rx_inst(
        .clk(clk),
        .rst_n(rst_n),
        .tick(tick), //fed from baud_gen_inst
        .rx(rx),
        .rx_byte(rx_byte),
        .rx_done(rx_done),
        .rx_error(rx_error),
        .rx_busy(rx_busy)
    );

endmodule
