# UART Echo On RoboMaster Dev Board Type-A

### Introduction

This project works on the **RoboMaster Development Board Type-A**. It receives message from **USART6**, and **send it back**. When this happens, the green LED on the board will flash once.

### Details

- To **avoid missing characters** due to function `HAL_UART_Transmit` occupying the CPU, the project uses `HAL_UARTEx_ReceiveToIdle_DMA` to receive messages. This will make sure that all characters in the message will be stored in the buffer before the callback function `HAL_UARTEx_RxEventCallback` is called.

- The size of the buffer is **256 bytes**. If a frame of message is longer than 256 characters, it **is possible** that the something be missed.