/*
 * user_i2c.c
 *
 *  Created on: 31 Jan 2021
 *      Author: sarun
 */

#include "user_i2c.h"
#
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_exti.h"
#include "stm32f4xx_hal_i2c.h"

#define I2Cx                             I2C1
#define I2C_OWN_ADDRESS        0x3E  /* Real 7 bits slave address value in Datasheet is: b0011111
                                    mean in uint8_t equivalent at 0x1F and this value can be
                                    seen in the OAR1 register in bits ADD[1:7] */

/* I2C handler declaration */
I2C_HandleTypeDef I2CxHandle;

extern HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);

void i2c_init()
{


	  /*Configure GPIO pin : PB6 */ //SCL in MX_GPIO_Init()
	  /*Configure GPIO pin : PB7 */ //SDA in MX_GPIO_Init()

	  I2CxHandle.Instance             = I2Cx;
	  I2CxHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	  I2CxHandle.Init.ClockSpeed      = 400000;
	  I2CxHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	  I2CxHandle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
	  I2CxHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	  I2CxHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
	  I2CxHandle.Init.OwnAddress1     = I2C_OWN_ADDRESS;
	  I2CxHandle.Init.OwnAddress2     = 0;

	  HAL_I2C_Init(&I2CxHandle);

	//  if(HAL_I2C_Init(&I2CxHandle) != HAL_OK)
	  {
	    /* Initialization Error */
	    //Error_Handler();
	  }
}

#define TXBUFFERSIZE 2
unsigned char aTxBuffer[2]={0xF8,0x56};
#define I2C_TARGET_ADDRESS 0x3C

int i2c_start_tx()
{
	return HAL_I2C_Master_Transmit_IT(&I2CxHandle, (uint16_t)I2C_TARGET_ADDRESS, (uint8_t*)aTxBuffer, TXBUFFERSIZE);
}


