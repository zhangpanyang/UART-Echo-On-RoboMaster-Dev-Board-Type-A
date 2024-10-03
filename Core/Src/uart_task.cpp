//
// Created by Sunny on 24-10-3.
//

#include "uart_task.h"

uint8_t rx_data[1];

void uartInit()
{
	HAL_UART_Receive_IT(&huart8, rx_data, sizeof(rx_data));
	HAL_UART_Transmit(&huart8, (uint8_t*)"init\n", 5, 100);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart8)
	{
		HAL_UART_Transmit(&huart8, rx_data, sizeof(rx_data), 100);
		HAL_UART_Receive_IT(&huart8, rx_data, sizeof(rx_data));
		HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
		// __HAL_TIM_SET_COUNTER(&htim6, 0);
		HAL_TIM_Base_Start_IT(&htim6);
	}
}

void  HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
	if (htim == &htim6)
	{
		// HAL_TIM_Base_Stop(&htim6);
		HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
	}
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}