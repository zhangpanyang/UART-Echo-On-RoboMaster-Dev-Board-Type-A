//
// Created by Sunny on 24-10-3.
//

#include "uart_task.h"
#include "main.h"
#include "usart.h"

uint8_t rx_data[16];

void uartInit()
{
	HAL_UART_Receive_IT(&huart8, rx_data, sizeof(rx_data));
	HAL_UART_Transmit(&huart8, (uint8_t*)"init\n", 5, 100);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	// if (huart == &huart8)
	{
		HAL_UART_Transmit(&huart8, (uint8_t*)"a", 1, 100);
		// HAL_UART_Transmit(&huart8, rx_data, sizeof(rx_data), 100);
		HAL_UART_Receive_IT(&huart8, rx_data, sizeof(rx_data));
	}
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}