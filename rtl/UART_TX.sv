//Takes a byte (parallel), shifts it out serially with start bit -> 8 data bits
//-> stop bit, using tick from baud_gen

module UART_TX(
    input logic clk, //system clock - needed to drive the internal state machine
    input logic rst_n, //active-low synchronous reset
    input logic tick, //16x oversamples tick from baud_gen - TX counts 16 of these per bit

    input logic[7:0] tx_data, //byte (8-bits) to transmit, must be valid when tx_start pulses
    input logic tx_start, //1-cycle pulse: "here's a new byte, begin sending it"

    output logic tx_busy, //high while a transmission is in progress

    output logic tx //serial line --> actual wire connecting to the receiver from the transmitter


    //signal line carrying bits *serially*, one at a time, over time.
);
    //step1: state encoding
    typedef enum logic[1:0] {
        IDLE = 2'b00,
        START = 2'b01,
        DATA = 2'b10,
        STOP = 2'b11
    } state_t;

    state_t state;
    //typedef enum creates a named type with 4 possible values
    //stored in 4-bits

    //step2: internal registers
    logic[3:0] tick_count; //counts 0-15 ticks = 1 bit period
    logic[2:0] bit_index; //counts 0-7, which data bit we're currently sending
    logic[7:0] tx_shift_reg; //holds a COPY of tx_data, latched when tx_start fires

    always_ff @(posedge clk) begin
        if(!rst_n) begin //this means reset is active
            state <= IDLE; //starting in IDLE, not sending anything
            tx <= 1'b1; //idle line convention: UART idles HIGH ????
            tx_busy <= 1'b0; //not busy, ready to accept a byte
            tick_count <= '0; //sub-tick counter starts at 0
            bit_index <='0; //bit_index starts at 0
        end else begin
            case (state)
            //IDLE: waiting for someone to hand us a byte to send
                IDLE: begin
                    tx<=1'b1; //keep driving line high (idle level)
                    if(tx_start) begin
                        //tx_start on logic high --> start sending the new byte (bit by bit)
                        tx_shift_reg <= tx_data; //latch data now so an exact copy is available.
                        tx_busy <= 1'b1; //telling the outside world "I'm busy"
                        tick_count <= '0; //reset sub-tick count for the START state
                        state <= START; //switch states
                    end
                end
                START: begin
                    //START state = drive the line low for exactly 1 bit period
                    //low pulse is a signal that lets RX know a new byte is incoming
                    tx<=1'b0;
                    if(tick) begin
                        //recall from baud_gen.sv, tick firest 16 times per bit period
                        if(tick_count==4'd15) begin
                            tick_count <= '0; //reset tick count
                            bit_index <= '0; //reset bit_index
                            state <= DATA;
                        end
                        else begin
                            tick_count <= tick_count + 1'b1; //not yet 16 ticks, keep incrementing
                        end
                    end
                end
                DATA: begin
                    //In DATA state, send all 8 bits of the byte, one by one
                    tx <= tx_shift_reg[bit_index]; //drive tx with the current bit index of the byte
                    if(tick) begin
                        if(tick_count == 4'd15) begin
                            //ONE full bit period has elapsed for THIS SPECIFIC BIT
                            tick_count <= '0;
                            if(bit_index==3'd7) begin
                                //just finished sending the last bit
                                state <= STOP;
                            end
                            else begin
                                bit_index <= bit_index + 1'b1;
                                //Because tick count has reached required 16 ticks,
                                //and beause the bit_index is still in the middle,
                                //this means to increment the bit_index.
                            end
                        end
                        else begin
                            tick_count <= tick_count + 1'b1;
                        end
                    end
                end
                STOP: begin
                    tx <= 1'b1;
                    if (tick) begin
                        if (tick_count == 4'd15) begin
                            tick_count <= 0;
                            tx_busy    <= 1'b0;
                            state      <= IDLE;
                        end
                        else begin
                            tick_count <= tick_count + 1'b1;
                        end
                    end
                end
            endcase
        end
    end


endmodule




//serial communication: one signal line carrying bits serially. One at a time, over time.
//parallel communication: (8-bit tx output) Implies 8 physical wires sending all bits simultaneously. This is not serial.
// https://www.circuitbasics.com/basics-uart-communication/



//Comments on the synchronous of UART communication protocol:

//asynchronous describes the relationship between TX and RX. they do not share a clock with each other

//Inside simulation/verilator, UART_TX is a synchronous digital circuit. clk is needed to advance
//its internal state, update bit counter, and register the tx output cleanly.

//What makes UART (universal async receiver/transmitter) asynchronous is that TX's clock
//and RX's clock are independent, unsynchronized clocks.

//TX doesn't wait for a signal from RX, and RX does not share TX's clock edges directly.
//Instead, both sides independently agree on timing via baud rate convention, and RX has to infer
//timing from incoming signals.

//In general, asynchronous is referring to no shared clocks between devices.
//EACH individual synchronous module inside one device needs its own local clock to function at all.