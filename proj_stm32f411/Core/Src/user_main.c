/*
 * user_main.c
 *
 *  Created on: Nov 1, 2020
 *      Author: sarun
 */
#include "user_main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_exti.h"


#include "FreeRTOS.h"


void ext_int7(void);

EXTI_HandleTypeDef extint7_handle = {7, &ext_int7};
EXTI_ConfigTypeDef extint_config = {EXTI_LINE_7,EXTI_MODE_INTERRUPT,EXTI_TRIGGER_RISING,EXTI_GPIOC};

volatile int intserv_routine=0;

void ext_int7(void)
{

	intserv_routine=1;

	///HAL_EXTI_IRQHandler(&extint7_handle);
}

//#include <stdio.h>

void wait(int X)
{
    for(int i=0;i<X;i++)
    {
        for(int j=0;j<1000;j++)
        {
      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
      	  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
        }
    }
}


#include "user_i2c.h"

HAL_StatusTypeDef ret=0;

void TASK_default_fn(void)
{

	ret = HAL_EXTI_SetConfigLine(&extint7_handle, &extint_config); //Configure ext int 7, using port C

	
	/*HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);*/

	//i2c_init();
    int status=5;
	//while(1)
	{

		status = i2c_start_tx();
	}

	float x;
	while(1)
	{
		//if(intserv_routine==1)
		{
		//	intserv_routine=0;

		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1); //Set Port D 15
		    wait(1000);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); //Set Port D 15
		    wait(1000);
		}
		x =10.25;
		x=x*3.5;
	}
}



void user_main()
{
	//user code

     //FreeRTOS
	  xTaskCreate ((TaskFunction_t)TASK_default_fn, "DEFAULT_TASK", (uint16_t)128/*stack*/, NULL, 20/*prio*/, NULL);
	  vTaskStartScheduler();
}

