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

void TASK1_default_fn(void)
{
//	ret = HAL_EXTI_SetConfigLine(&extint7_handle, &extint_config); //Configure ext int 7, using port C

		/*HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);*/

	//i2c_init();
   // int status=5;
	//while(1)
	{

	//	status = i2c_start_tx();
	}

	float x;
	x =10.25;
	while(1)
	{
		//if(intserv_routine==1)
		{
		//	intserv_routine=0;
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1); //Set Port D 15
		    vTaskDelay( 500 );
		 //   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); //Set Port D 15
		//    vTaskDelay( 250 );
		}
		x=x*3.5;
	}
	vTaskDelete(NULL);
}


void TASK2_default_fn(void)
{
	while(1)
	{
		vTaskDelay( 300 );
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0); //Set Port D 15
	}
	vTaskDelete(NULL);
}

void timerfunc()
{


}

#include "timers.h"
//#include "misc.h"
void user_main()
{
	//user code


	/* Ensure all priority bits are assigned as preemption priority bits. */
	//NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	


     //FreeRTOS
	  xTaskCreate ((TaskFunction_t)TASK1_default_fn, "APP1_TASK", (uint16_t)1024/*stack*/, NULL, 20/*prio*/, NULL);
	  xTaskCreate ((TaskFunction_t)TASK2_default_fn, "APP2_TASK", (uint16_t)1024/*stack*/, NULL, 15/*prio*/, NULL);
	//TimerHandle_t *timer = xTimerCreate( "newtimer",100, 1, NULL, timerfunc );

	// xTimerStart( timer, 0 );

	  vTaskStartScheduler();
}

