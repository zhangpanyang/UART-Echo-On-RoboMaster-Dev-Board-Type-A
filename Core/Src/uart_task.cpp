//
// Created by Sunny on 24-10-3.
//

#include "uart_task.h"

uint8_t rx_data[256];

void uartInit()
{
	__HAL_UART_ENABLE_IT(&huart6, UART_IT_IDLE);

	HAL_UARTEx_ReceiveToIdle_DMA(&huart6, rx_data, sizeof(rx_data));
	HAL_UART_Transmit(&huart6, (uint8_t*)"init\n", 5, 100);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	HAL_UART_Transmit_IT(&huart6, rx_data, sizeof(rx_data));
	HAL_UARTEx_ReceiveToIdle_DMA(&huart6, rx_data, sizeof(rx_data));

	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
	__HAL_TIM_SET_COUNTER(&htim6, 0);
	HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart6)
	{
		HAL_UART_Transmit_IT(&huart6, rx_data, sizeof(rx_data));
		HAL_UART_Receive_DMA(&huart6, rx_data, sizeof(rx_data));
	}
}

void  HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim6)
	{
		HAL_TIM_Base_Stop(&htim6);
		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
	}
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}