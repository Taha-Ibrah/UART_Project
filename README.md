# UART Transmitter & Receiver with FIFO

A hardware implementation of a UART communication system written in SystemVerilog, featuring 16× oversampling, parameterized FIFO buffering, and self-checking verification using Python, cocotb, and Verilator.

## Overview

This project implements a complete UART transmit and receive datapath for asynchronous serial communication. The design consists of a baud-rate generator, UART transmitter, UART receiver, and parameterized FIFO buffers for handling data between the UART modules and external logic.

The design is verified using cocotb testbenches running with Verilator.

## Features

- UART transmitter and receiver written in SystemVerilog
- 9600 baud operation
- 16× oversampling for receive timing
- FSM-based TX and RX control
- Parameterized FIFO buffers
- Circular-buffer FIFO architecture
- Start, data, and stop bit handling
- Self-checking Python testbenches using cocotb
- Simulation and verification with Verilator

## Architecture

```
                    UART System

          TX Path                     RX Path

    Input Data                  Serial RX
        │                           │
        ▼                           ▼
    ┌────────┐                  ┌────────┐
    │ TX FIFO│                  │UART RX │
    └───┬────┘                  └───┬────┘
        │                           │
        ▼                           ▼
    ┌────────┐                  ┌────────┐
    │UART TX │                  │ RX FIFO│
    └───┬────┘                  └───┬────┘
        │                           │
        ▼                           ▼
    Serial TX                  Output Data

              ┌───────────────┐
              │ Baud Generator│
              │ 16× UART Tick │
              └───────────────┘
```

## Modules

### Baud Rate Generator

Generates the timing tick used by the UART transmitter and receiver. The design uses a 16× oversampling clock relative to the configured baud rate.

For a 50 MHz system clock and 9600 baud:

```
Oversampling frequency = 9600 × 16 = 153,600 Hz

Divisor ≈ 50,000,000 / 153,600 ≈ 325
```

### UART Transmitter

The transmitter converts parallel data into a UART serial frame using an FSM.

```text
IDLE → START → DATA → STOP → IDLE
```

Each transmission contains:

```text
Start Bit | 8 Data Bits | Stop Bit
    0     | D0 ... D7   |    1
```

Data is transmitted least-significant bit first.

### UART Receiver

The receiver reconstructs incoming UART frames using 16× oversampling.

The receiver detects the falling edge of the start bit, samples near the center of each bit period, reconstructs the 8-bit data word, and verifies the stop bit.

### FIFO

Parameterized FIFO buffers are used to decouple UART timing from external data producers and consumers.

The FIFO uses a circular-buffer architecture with:

- Configurable data width
- Configurable depth
- Read and write pointers
- Full and empty detection

## Verification

The design is tested using Python-based cocotb testbenches with Verilator as the simulator.

Verification includes:

- Baud tick timing and pulse width
- UART TX frame generation
- UART RX data reconstruction
- Start and stop bit behavior
- FIFO read/write operation
- FIFO full and empty conditions
- Multiple sequential byte transfers
- Reset behavior

Self-checking tests compare simulated outputs against expected UART behavior.

## Tools

- **SystemVerilog** — RTL design
- **Python** — Verification and test generation
- **cocotb** — Python-based HDL testbench framework
- **Verilator** — SystemVerilog simulation
- **Git** — Version control

## Project Structure

```text
uart/
├── rtl/
│   ├── baud_gen.sv
│   ├── uart_tx.sv
│   ├── uart_rx.sv
│   ├── fifo.sv
│   └── uart_top.sv
│
├── tests/
│   ├── test_baud_gen.py
│   ├── test_uart_tx.py
│   ├── test_uart_rx.py
│   └── test_fifo.py
│
├── Makefile
└── README.md
```

*File names and directory structure may differ from the actual repository.*


## Purpose

This project was built to develop practical experience with RTL design, finite-state machines, serial communication protocols, buffering, clock-based timing, and hardware verification using modern Python-based verification tools.
