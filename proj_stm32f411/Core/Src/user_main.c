/*
 * user_main.c
 *
 *  Created on: Nov 1, 2020
 *      Author: sarun
 */
#include "user_main.h"
#include "stm32f4xx_hal.h"

void user_main()
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);

	    for(int i=0;i<10000;i++)
	    {
	        for(int j=0;j<1000;j++)
	        {
	      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	        }
	    }

	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);

	    for(int i=0;i<10000;i++)
	    {
	        for(int j=0;j<1000;j++)
	        {
	      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	        }
	    }

	}

}

