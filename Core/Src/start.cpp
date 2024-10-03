//
// Created by Sunny on 24-10-3.
//

#include "start.h"
#include "main.h"
#include "uart_task.h"

uint8_t message[] = "RoboMaster Is Good!\n";

void startup()
{
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
	uartInit();
	while (1)
	{
		// HAL_Delay(1000);
		// HAL_UART_Transmit(&huart8, message, sizeof(message), 100);
	}
}
