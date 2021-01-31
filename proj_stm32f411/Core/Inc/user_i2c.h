/*
 * user_i2c.h
 *
 *  Created on: 31 Jan 2021
 *      Author: sarun
 */

#ifndef INC_USER_I2C_H_
#define INC_USER_I2C_H_


#define HAL_I2C_MODULE_ENABLED


#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_exti.h"
#include "stm32f4xx_hal_i2c.h"


void i2c_init(void);
int i2c_start_tx(void);

#endif /* INC_USER_I2C_H_ */
