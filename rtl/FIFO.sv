//Why there is a need for a FIFO module
//UART TX send bits at a fixed, slow rate (9600 baud), but whatever is feeding data to UART_TX
//might produce bytes in bursts, or faster than UART can send them.

//Without a FIFO: if you assert tx_start with new data while UART_TX is still shifting out the previous byte
//it risks corrupting the data or stall

//FIFO's job: decouple producer and consumer in time
//Producer writes bytes into the FIFO whenver it wants
//UART_TX pulls bytes out of the FIFO whenever it's ready for the next one
//Same idea on RX side: UART_RX receives a byte and pushes into a FIFO, and the consumer (CPU, testbench, etc.)
//reads it out whenever its ready, even if RX has already received several more bytes in the meantime

module FIFO#(
    parameter int DATA_WIDTH = 8,
    parameter int DEPTH = 16,                //how many bytes the FIFO can store at once
    parameter int ADDR_WIDTH = $clog2(DEPTH) //bits to index DEPTH slots (need 4 bits for 16 slots)
    )(
    input logic clk,                        //internal clock
    input logic rst_n,                      //internal reset

    input logic wr_en,                      //writer requests a push
    input logic[DATA_WIDTH-1:0] wr_data,    //data to push
    output logic full,                      //1=no room, writer must wait

    input logic rd_en,                      //reader requests a pop
    output logic[DATA_WIDTH-1:0] rd_data,   //oldest unread entry
    output logic empty                      //1 = nothing to read
);

    //Internals needed: Memory array, write pointer, read pointer, some way to derive.
    //write pointer: ponts at the next empty slot to fill. Every push, it advances
    //read pointer: points at the oldest unread slot. Every pop. it advances

    //when a pointer runs off the end of the array, it wraps back to 0.

    //Storage: DEPTH slots, each DATA_WIDTH bits wide.
    logic[DATA_WIDTH-1: 0] mem [0: DEPTH-1];
    //UNPACKED RANGE: describes array indices - which element of the array, not bits within a word

    //Pointers to the next slot to write/read. They wrap automatically
    //Because they are exactly ADDR_WIDTH bits wide (15+1 -> 0)
    logic[ADDR_WIDTH-1:0] wr_ptr; //as many bits wide needed to index slots
    logic[ADDR_WIDTH-1:0] rd_ptr;

    //How many entries are currently stored. Needs ADDR_WIDTH+1 bits so it can
    //hold 0 ... DEPTH inclusive (0...16 needs 5 bits)
    logic[ADDR_WIDTH:0] count;

    //------status flags------
    // NOTE: DEPTH is cast to count's own width before comparing — DEPTH is an
    // untyped int parameter (32 bits) while count is only ADDR_WIDTH+1 bits
    // (5 bits for DEPTH=16), and Verilator flags the implicit widening.
    assign full = (count == (ADDR_WIDTH+1)'(DEPTH));
    assign empty = (count==0);

    //reading data:
    //Oldest unread byte is ALWAYS presented on rd_data. The reader just pulses rd_en to advance past it.
    //Must check empty before trusting rd_data
    assign rd_data = mem[rd_ptr];

    //write: store data and advance write pointer
    always_ff @(posedge clk) begin
        if(!rst_n) begin
            wr_ptr <= '0;
        end else if(wr_en && !full) begin
            mem[wr_ptr] <= wr_data;
            wr_ptr <= wr_ptr + 1;
        end
    end

    //read: advance read pointer
    //NOTE: reading does NOT touch mem — rd_data already presents mem[rd_ptr]
    //combinationally (see assign above). Popping just advances the pointer so
    //the next-oldest byte becomes visible.
    always_ff @(posedge clk) begin
        if(!rst_n) begin
            rd_ptr <= '0;
        end else if(rd_en && !empty) begin
            rd_ptr <= rd_ptr + 1;
        end
    end


    //occupancy counter:
    //look at whether a real write and/or real read happened this cycle
    //and adjust count accordingly
    always_ff @(posedge clk) begin
        if(!rst_n) begin
            count <= '0;
        end else begin
            case({wr_en && !full , rd_en && !empty})
                2'b10: count <= count + 1; //write when not full
                2'b01: count <= count - 1; //read when not empty
                default: count <= count;
            endcase
        end
    end

endmodule