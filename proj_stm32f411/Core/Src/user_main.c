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


void blueresetbutton_action(void);

void blueresetbutton_action(void)
{
    static unsigned char toggleled=0;
    toggleled^=1;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, toggleled); //Set PortD 15 Blue led
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

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, 1); //Set PortD 12 Green led
		vTaskDelay( 500 );
		//   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, 0); //Clear PortD 12 Green led
		//    vTaskDelay( 250 );
		x=x*3.5;
	}
	vTaskDelete(NULL);
}


void TASK2_default_fn(void)
{
	while(1)
	{
		vTaskDelay( 300 );
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, 0); //Clear PortD 12 Green led
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

