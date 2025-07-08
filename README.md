UART Transmit (Bare-Metal) on STM32F401RE:-
This project demonstrates how to implement UART (USART2) transmit functionality using bare-metal programming with CMSIS on the STM32 Nucleo-F401RE board. No HAL libraries or CubeMX were used — just pure register-level control.

What It Does:
- Initializes USART2 (PA2 as TX) for 9600 baud transmission
- Sends "Hello from STM32!" repeatedly over UART
- Uses TXE (Transmit Data Register Empty) flag for safe transmission
- Transmits data via the ST-Link Virtual COM Port (USB)
  
Hardware:-
- Board: STM32 Nucleo-F401RE
- TX Pin: PA2 (USART2_TX via ST-Link VCP)
- USB: Micro-USB to PC (no extra wiring needed)
- Terminal: Arduino Serial Monitor / PuTTY / Tera Term

Baud Rate:-
- 9600 bps @ 16 MHz system clock
- BRR = 0x0683 (Pre-calculated for 16 MHz)

Tools Used:
- Language: C (Bare-Metal)
- Toolchain: ARM CMSIS (no HAL)
- IDE: Keil uVision5 / STM32CubeIDE
- Debugger: Onboard ST-Link

How to Use:
1. Clone the CODE to your IDE WITH required cmsis and startup files (Keil or STM32CubeIDE).
2. Build and flash the code to your STM32 Nucleo-F401RE.
3. Open a serial terminal on the correct COM port at 9600 baud.
4. Observe "Hello from STM32!" printing continuously.
