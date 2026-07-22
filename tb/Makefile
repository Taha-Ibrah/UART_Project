SIM = verilator
TOPLEVEL_LANG = verilog

VERILOG_SOURCES = $(PWD)/../rtl/baud_gen.sv $(PWD)/../rtl/UART_RX.sv $(PWD)/../rtl/UART_RX_tl.sv
TOPLEVEL = UART_RX_tl
MODULE = UART_RX_test

include $(shell cocotb-config --makefiles)/Makefile.sim