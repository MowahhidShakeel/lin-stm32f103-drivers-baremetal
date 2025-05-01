# Baremetal Drivers for STM32F103

This repository contains a collection of low-level drivers written from scratch for the STM32F103 microcontroller using **baremetal programming** (no HAL or external libraries). The goal of this project is to understand and implement the fundamental building blocks required to control hardware directly via memory-mapped registers.

## Features

The following drivers and components are implemented:

- **GPIO (General Purpose Input/Output)**  
  Direct register-level control of input and output pins.

- **UART (Universal Asynchronous Receiver-Transmitter)**  
  Serial communication implemented without standard libraries.

- **TIMERS**  
  Precise timing functionality for delays, PWM, and periodic tasks.

- **LIN (Local Interconnect Network)**  
  Basic LIN protocol support using UART in slave mode.

- **Startup Code**  
  Custom startup assembly and vector table setup for STM32F103.

## Directory Structure
```
Baremetal_Programming/
├── LICENSE
├── LinApp.bat
├── README.md
├── debug.bat
├── platform/
└── ssc/
    ├── doc/
    ├── inc/
    │   ├── Gpio.h
    │   ├── lin.h
    │   ├── peripheral.h
    │   ├── rcc.h
    │   ├── timer.h
    │   └── usart.h
    └── src/
        ├── Gpio.c
        ├── lin.c
        ├── main.c
        ├── peripheral.c
        ├── rcc.c
        ├── timer.c
        └── usart.c
```

## Getting Started

### Prerequisites

- STM32F103 Development Board (e.g., Blue Pill)
- ARM Toolchain (`arm-none-eabi-gcc`)
- OpenOCD or ST-Link Utility for flashing
- Serial Terminal (e.g., PuTTY or minicom)

### Build Instructions

You can build the project from WSL/Linux using Make or directly from Windows using the provided `.bat` scripts.  
To run from WSL:
```bash
cmd.exe /c LinApp.bat
```



