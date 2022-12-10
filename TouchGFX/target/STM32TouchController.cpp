/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file is generated by TouchGFX Generator 4.19.1.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
extern "C" {
#include "TargetDisplay.h"
}
void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
	TOUCH_Init();
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */
	if(TOUCH_IsPressed())	//can be omitted -> controller continuously read touch data via i2c
	{
		TOUCH_Reset();		//can be omitted
		TOUCH_Data td=TOUCH_GetData();
		if(td.p>TP_MIN_PRESSURE)
		{
			x=td.x;
			y=td.y;
			return true;
		}
	}
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
