/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ili9341_driver.h"
#include "OSC.h"
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile bool isPlaying = false;
/* 测试使用的一个周期的正弦波 */
const uint16_t gOutputSignal[] = {2048, 2248, 2447, 2642, 2831, 3013,
    3185, 3347, 3496, 3631, 3750, 3854, 3940, 4007, 4056, 4086, 4095, 4086,
    4056, 4007, 3940, 3854, 3750, 3631, 3496, 3347, 3185, 3013, 2831, 2642,
    2447, 2248, 2048, 1847, 1648, 1453, 1264, 1082, 910, 748, 599, 464, 345,
    241, 155, 88, 39, 9, 0, 9, 39, 88, 155, 241, 345, 464, 599, 748, 910, 1082,
    1264, 1453, 1648, 1847};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  /*** 屏幕测试 ***/
  ILI9341_init(BLACK);


     /* OSC_Config的每项设置查看OSC_Config_TypeDef的定义位置，有注释 */
    OSC_Config_TypeDef OSC_Config;

    uint16_t ruler_y[5] = {1000, 2000, 3000, 4000, 0};
    uint16_t ruler_x[5] = {30, 50, 90, 0, 0};

    OSC_Config.x_origin = 10;
    OSC_Config.y_origin = 0;
    OSC_Config.x_width  = 200;
    OSC_Config.y_width  = 120;

    OSC_Config.display_num_min = 0;
    OSC_Config.display_num_max = 4095;

    OSC_Config.channel_num = 2;

    OSC_Config.is_display_ruler_y = true;
    OSC_Config.ruler_y = &ruler_y[0];
    OSC_Config.ruler_count_y = 4;
    OSC_Config.ruler_num_digits_y = 4;

    OSC_Config.is_display_ruler_x = true;
    OSC_Config.ruler_x = &ruler_x[0];
    OSC_Config.ruler_count_x = 3;
    OSC_Config.ruler_zero_value_x = 0;
    OSC_Config.ruler_full_value_x = 100;
    OSC_Config.ruler_num_digits_x = 8;

    OSC_Config.theme_type = OSC_THEME_DEFAULT;
    OSC_Config.is_auto_clear = true;

    OSC_Init(OSC_INST(0), &OSC_Config);
    OSC_ReDraw(OSC_INST(0));

    OSC_Config.x_origin = 0;
    OSC_Config.y_origin = 120;
    OSC_Config.theme_type = OSC_THEME_LIGHT;

    OSC_Init(OSC_INST(1), &OSC_Config);
    OSC_ReDraw(OSC_INST(1));

    int demo_signal_size = sizeof(gOutputSignal) / sizeof(gOutputSignal[0]);
    int num = 0;
    int num_1 = 32;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
        /* 查表输出 */
        OSC_CurveDraw(OSC_INST(0), gOutputSignal[num], gOutputSignal[num_1]);
        OSC_CurveDraw(OSC_INST(1), gOutputSignal[num_1], gOutputSignal[num]);
        HAL_Delay(10);
        num++;num_1++;
        if(num == demo_signal_size) {
            num = 0;
        }
        if(num_1 == demo_signal_size) {
            num_1 = 0;
        } 
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
