//RECALL: tick is shared time measurement (local unit of time)
//TX generates timing - defines when each bit starts and ends

//RX algorithm explain:
//RX watches the line (tx signal), RX detects high-to-low transition
//-The catch: the edge could happen at any point relative to RX's own tick counter
//-This is because there is no shared clock between RX and TX (asynchronous)
//-Once the start edge is confrimed, RX modules counts ticks forward to land on the
//middle of each subsequent bit (whole reason of 16x oversampling).
//Continue sampling the middle of each subsequent bit, then sample the stop bit


module UART_RX(
    input logic clk, //internal clock signal
    input logic rst_n, //active-low reset
    input logic tick,

    input logic rx, //input is coming from the output of the TX module

    output logic [7:0] rx_byte, //the fully assembled byte
    output logic rx_done, // single pulse, RX telling downstream logic that a byte is complete
    output logic rx_error, //bit to protect RX from framing error (mismatch)
    //rx_error would pulse when mismatch is detected.
    output logic rx_busy //some logic signals should be utilized for OBSERVABILITY
    //These signals is what makes it easy to check/verify from outside
);

//Both TX and RX have the same relative code structure
//Both moduels are syncrhonous state machines
//RX is receiving/inferring timing instead of generating it


    //step1: state encoding
    typedef enum logic[1:0] {
        IDLE = 2'b00,
        START = 2'b01,
        DATA = 2'b10,
        STOP = 2'b11
    } state_t;

    state_t state;

    //step2: internal registers
    logic[3:0] tick_count;
    logic[2:0] bit_index;
    logic[7:0] rx_shift_reg; //rx_byte latches on during the stop state
    logic rx_prev; //detect the start-bit edge

    always_ff @(posedge clk) begin
        if(!rst_n) begin
            state <= IDLE;
            // REMOVED: "rx <= 1'b1;" — rx is a MODULE INPUT, it must never be driven here
            rx_prev <= 1'b1;
            rx_error <= 1'b0;
            rx_busy <=1'b0;
            rx_done <= 1'b0;
            bit_index <= 3'b0;
            tick_count <= 4'b0;
        end else begin
            // ADDED: unconditional rx_prev update — this was never assigned before, so edge detection could never see a transition after cycle 1
            rx_prev <= rx;
            case(state)
            IDLE: begin //IDLE - nothing is happening
                rx_busy <= 1'b0;
                rx_done <= 1'b0;
                rx_error <= 1'b0; //clear any progress
                //First thing is edge detection.
                if(rx==1'b0 && rx_prev==1'b1) begin
                    // ADDED: begin/end — previously only rx_busy was inside the if, so
                    // tick_count/bit_index/state were assigned UNCONDITIONALLY every cycle,
                    // forcing state to START immediately regardless of rx
                    //Signals that rx transitioned high-to-low
                    rx_busy <= 1'b1;
                    tick_count <= '0;
                    bit_index <= '0;
                    state<= START; //officially starting
                end

            end
            START: begin
                if(tick) begin
                    if(tick_count ==4'd15) begin
                        tick_count <= '0;
                        state<=DATA;
                    end
                    else if(tick_count == 4'd8) begin
                        if(rx==1'b0) begin //rx is still low
                            tick_count <=tick_count + 1'b1;
                        end
                        else begin //glitch, not a real start bit
                            state <= IDLE;
                        end
                    end
                    else begin
                        tick_count <= tick_count + 1'b1;
                    end
                end
            end
            DATA: begin //these are the main 8 bits
                if(tick) begin //waiting on tick
                    if(bit_index == 3'b111) begin
                        if(tick_count == 4'd8) begin
                            rx_shift_reg[bit_index] <= rx;
                            tick_count <= tick_count + 1'b1;
                        end
                        else if(tick_count == 4'd15) begin
                            bit_index <= bit_index + 1'b1;
                            tick_count <= '0;
                            //updating.....
                            rx_byte <= rx_shift_reg;
                            state <= STOP;
                        end
                        else begin
                            tick_count <= tick_count + 1'b1;
                        end
                    end
                    else begin
                        if(tick_count == 4'd8) begin
                            rx_shift_reg[bit_index] <= rx;
                            tick_count <= tick_count + 1'b1;
                        end
                        else if(tick_count == 4'd15) begin
                            bit_index <= bit_index + 1'b1;
                            tick_count <= '0;
                        end
                        else begin
                            tick_count <= tick_count + 1'b1;
                        end
                    end
                end
            end
            STOP: begin
                // FIXED: rx_done/rx_error must be single-CLOCK-CYCLE pulses, not
                // held across the whole rest of STOP. Previously rx_done <= 1'b1
                // was set at tick_count==8 and only cleared at tick_count==15 —
                // that's ~7 ticks (thousands of clk cycles) of rx_done sitting
                // high, during which UART.sv's RX FIFO (wr_en tied to rx_done)
                // pushed the same byte in on every single clock edge, filling
                // the FIFO with 16 copies of one received byte instead of 1.
                // Defaulting low here every cycle, and only pulsing high for the
                // exact tick_count==8 edge below, makes it a true 1-cycle pulse.
                rx_done  <= 1'b0;
                rx_error <= 1'b0;
                if(tick) begin
                    if(tick_count == 4'd8) begin
                        if(rx==1'b1)begin
                            rx_done <=1'b1;
                        end
                        else begin
                            rx_error <=1'b1;
                            // REMOVED: "state<=IDLE;" here — jumping straight to IDLE on
                            // error meant tick_count never reached 15, so rx_busy
                            // never got cleared on the error path either (same stuck bug)
                        end
                        // ADDED: this increment was missing, so tick_count got stuck at 8
                        // forever (this branch never advanced it), and STOP could never
                        // reach tick_count==15 to return to IDLE — RX hung in STOP permanently
                        tick_count <= tick_count + 1'b1;
                    end
                    else if(tick_count == 4'd15) begin
                        tick_count <= '0;
                        rx_busy <='0;
                        state<=IDLE; //done. Not doing anything.
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