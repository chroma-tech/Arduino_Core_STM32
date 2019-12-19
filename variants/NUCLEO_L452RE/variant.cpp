/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
#ifdef ARDUINO_NUCLEO_L452RE
  PA_3,  //D0
  PA_2,  //D1
  PA_10, //D2
  PB_3,  //D3
  PB_5,  //D4
  PB_4,  //D5
  PB_10, //D6
  PA_8,  //D7
  PA_9,  //D8
  PC_7,  //D9
  PB_6,  //D10
  PA_7,  //D11
  PA_6,  //D12
  PA_5,  //D13 - LED
  PB_9,  //D14
  PB_8,  //D15
  // ST Morpho
  // CN7 Left Side
  PC_10, //D16
  PC_12, //D17
  PA_13, //D18 - SWD
  PA_14, //D19 - SWD
  PA_15, //D20
  PB_7,  //D21
  PC_13, //D22
  PC_14, //D23
  PC_15, //D24
  PH_0,  //D25
  PH_1,  //D26
  PC_2,  //D27
  PC_3,  //D28
  // CN7 Right Side
  PC_11, //D29
  PD_2,  //D30
  // CN10 Left Side
  PC_9,  //D31
  // CN10 Right side
  PC_8,  //D32
  PC_6,  //D33
  PC_5,  //D34
  PA_12, //D35
  PA_11, //D36
  PB_12, //D37
  PB_11, //D38
  PB_2,  //D39
  PB_1,  //D40
  PB_15, //D41
  PB_14, //D42
  PB_13, //D43
  PC_4,  //D44
  PA_0,  //D45/A0
  PA_1,  //D46/A1
  PA_4,  //D47/A2
  PB_0,  //D48/A3
  PC_1,  //D49/A4
  PC_0   //D50/A5
#else
  PA_10, //D0
  PA_9,  //D1
  PA_12, //D2
  PB_3,  //D3
  PB_5,  //D4
  PA_15, //D5
  PB_10, //D6
  PC_7,  //D7
  PB_6,  //D8
  PA_8,  //D9
  PA_11, //D10
  PB_15, //D11
  PB_14, //D12
  PB_13, //D13 - LED
  PB_7,  //D14
  PB_8,  //D15
  // ST Morpho
  // CN5 Left Side
  PC_10, //D16
  PC_12, //D17
  PB_12, //D18
  PA_13, //D19 - SWD
  PA_14, //D20 - SWD
  PC_13, //D21
  PC_14, //D22
  PC_15, //D23
  PH_0,  //D24
  PH_1,  //D25
  PB_4,  //D26
  PB_9,  //D27
  // CN5 Right Side
  PC_11, //D28
  PD_2,  //D29
  // CN6 Left Side
  PC_9,  //D30
  // CN6 Right side
  PC_8,  //D31
  PC_6,  //D32
  PC_5,  //D33
  PB_0,  //D34
  PB_11, //D35
  PB_2,  //D36
  PB_1,  //D37
  PA_7,  //D38
  PA_6,  //D39
  PA_5,  //D40
  PA_4,  //D41
  PC_4,  //D42
  PA_3,  //D43
  PA_2,  //D44
  PA_0,  //D45 // A0
  PA_1,  //D46 // A1
  PC_3,  //D47 // A2
  PC_2,  //D48 // A3
  PC_1,  //D49 // A4
  PC_0   //D50 // A5
#endif
};

// Analog (Ax) pin number array
const uint32_t analogInPin[] = {
  45, //A0
  46, //A1
  47, //A2
  48, //A3
  49, //A4
  50, //A5
#ifdef ARDUINO_NUCLEO_L452RE
  11, //A6
  12, //A7
  27, //A8
  28, //A9
  44  //A10
#else
  41, //A6
  40, //A7
  39, //A8
  38, //A9
  34, //A10
  37, //A11
  42  //A12
#endif
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
  *            PLL_M                          = 1
  *            PLL_N                          = 40
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 2
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /* Configure LSE Drive Capability */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
    Error_Handler();
  }
  /* Configure the main internal regulator output voltage */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK) {
    Error_Handler();
  }
  /* Enable MSI Auto calibration */
  HAL_RCCEx_EnableMSIPLLMode();
}

#ifdef __cplusplus
}
#endif
