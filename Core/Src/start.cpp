//
// Created by Sunny on 24-10-3.
//

#include "start.h"

#include "main.h"
#include "usart.h"

void startup()
{
	while (1)
	{
		HAL_Delay(1000);
		HAL_UART_Transmit(&huart8, (uint8_t *)"a", 1, 100);
	}
}
