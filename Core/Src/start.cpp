//
// Created by Sunny on 24-10-3.
//

#include "start.h"

#include "main.h"
#include "usart.h"

uint8_t message[] = "RoboMaster Is Good!\n";

void startup()
{
	while (1)
	{
		HAL_Delay(1000);
		HAL_UART_Transmit(&huart8, message, sizeof(message)-1, 100);
	}
}
