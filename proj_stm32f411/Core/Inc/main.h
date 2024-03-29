/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define User_Button_On_board_Pin GPIO_PIN_0
#define User_Button_On_board_GPIO_Port GPIOA
#define User_Button_On_board_EXTI_IRQn EXTI0_IRQn
#define Audio_WS_Pin GPIO_PIN_4
#define Audio_WS_GPIO_Port GPIOA
#define Green_LED_Pin GPIO_PIN_12
#define Green_LED_GPIO_Port GPIOD
#define Orange_LED_Pin GPIO_PIN_13
#define Orange_LED_GPIO_Port GPIOD
#define Red_LED_Pin GPIO_PIN_14
#define Red_LED_GPIO_Port GPIOD
#define Blue_LED_Pin GPIO_PIN_15
#define Blue_LED_GPIO_Port GPIOD
#define Audio_MCK_Pin GPIO_PIN_7
#define Audio_MCK_GPIO_Port GPIOC
#define Audio_CK_Pin GPIO_PIN_10
#define Audio_CK_GPIO_Port GPIOC
#define Audio_Data_Pin GPIO_PIN_12
#define Audio_Data_GPIO_Port GPIOC
#define To_Audio_DAC_I2C_CLK_Pin GPIO_PIN_6
#define To_Audio_DAC_I2C_CLK_GPIO_Port GPIOB
#define To_Audio_DAC_I2C_data_Pin GPIO_PIN_9
#define To_Audio_DAC_I2C_data_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
