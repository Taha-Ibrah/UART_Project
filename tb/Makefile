SIM = verilator
TOPLEVEL_LANG = verilog

VERILOG_SOURCES = $(PWD)/../rtl/baud_gen.sv $(PWD)/../rtl/UART_TX.sv $(PWD)/../rtl/UART_TX_tl.sv
TOPLEVEL = UART_TX_tl
MODULE = UART_TX_test

include $(shell cocotb-config --makefiles)/Makefile.sim