//
// Created by Sunny on 24-10-3.
//

#include "uart_task.h"

uint8_t rx_data[256];

void uartInit()
{
	__HAL_UART_ENABLE_IT(&huart8, UART_IT_IDLE);

	HAL_UART_Receive_DMA(&huart8, rx_data, sizeof(rx_data));
	HAL_UART_Transmit(&huart8, (uint8_t*)"init\n", 5, 100);
}

void UART8_IRQHandler(void)
{
	if(__HAL_UART_GET_FLAG(&huart8, UART_FLAG_IDLE) != RESET)
	{
		__HAL_UART_CLEAR_FLAG(&huart8, UART_FLAG_IDLE);
		HAL_UART_Transmit_IT(&huart8, rx_data, sizeof(rx_data));
		HAL_UART_Receive_DMA(&huart8, rx_data, sizeof(rx_data));

		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SET_COUNTER(&htim6, 0);
		HAL_TIM_Base_Start_IT(&htim6);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart8)
	{
		HAL_UART_Transmit_IT(&huart8, rx_data, sizeof(rx_data));
		HAL_UART_Receive_DMA(&huart8, rx_data, sizeof(rx_data));
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