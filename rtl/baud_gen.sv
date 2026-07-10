//Serial Communication Protocols: A way to send data sequentially over a single/communication channel

//Universal Asynchronous Receiver-Transmitter
//Uses 2 wires. One for sending and one for receiving.
//No shared clock between the two devices, thus they are asynchronous.
//Instead, both devices agree on a speed (baud rate) before communicating

//Baud Rate: The number of signal transitions per second. At 9600 baud, each communication bit is
// 1/9600th of a second.

//Because UART is Async, the baud rate is an agreement on how fast the communication will be.

module baud_gen #(
    parameter CLK_FREQ = 50_000_000, //system clock frequency
    parameter BAUD_RATE = 9600 //target baud
) (
    input logic clk, //system clock
    input logic rst_n, //active-low synchronous reset
    output logic tick //pulses high for 1 clk cycle at 16x baud rate
);

    //Divisor: how many system clock cycles make up one 16x sub-tick period.
    localparam int DIVISOR = CLK_FREQ / (BAUD_RATE * 16);
    //Results in 325.52 --> 325.


    //CNT_WIDTH: This returns the minimum number of bits needed to represent value DIVISOR-1
    //(max value the counter can hold).
    localparam int CNT_WIDTH = $clog2(DIVISOR); //built-in sv function

    logic [CNT_WIDTH-1:0] count;  // counts up each clk cycle

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            count <= '0;      // reset counter
            tick  <= 1'b0;    // reset tick low
        end else if (count == unsigned'(CNT_WIDTH'(DIVISOR - 1))) begin
            count <= '0;      // wrap counter
            tick  <= 1'b1;    // pulse tick this cycle
        end else begin
            count <= count + 1'b1;  // keep counting
            tick  <= 1'b0;           // tick stays low
        end
    end
    
endmodule
