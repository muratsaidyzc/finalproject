/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "string.h"
#include "MY_LIS3DSH.h"
#include <stdio.h>
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

using namespace ei;

// paste the raw features here
static const float features[] = {55.9577, -5.4036, 525.5946, 56.7960, -5.4996, 533.3694, 57.5427, -5.5881, 540.2832, 58.1988, -5.6693, 546.3459, 58.7658, -5.7433, 551.5727, 59.2458, -5.8103, 555.9843, 59.6413, -5.8706, 559.6060, 59.9556, -5.9245, 562.4681, 60.1920, -5.9723, 564.6053, 60.3548, -6.0144, 566.0564, 60.4481, -6.0511, 566.8639, 60.4769, -6.0829, 567.0737, 60.4462, -6.1103, 566.7347, 60.3614, -6.1337, 565.8982, 60.2279, -6.1536, 564.6177, 60.0516, -6.1706, 562.9483, 59.8384, -6.1850, 560.9461, 59.5942, -6.1975, 558.6678, 59.3249, -6.2084, 556.1706, 59.0366, -6.2184, 553.5108, 58.7351, -6.2279, 550.7444, 58.4260, -6.2373, 547.9257, 58.1151, -6.2472, 545.1075, 57.8075, -6.2578, 542.3402, 57.5084, -6.2696, 539.6715, 57.2226, -6.2829, 537.1464, 56.9543, -6.2981, 534.8059, 56.7077, -6.3154, 532.6877, 56.4862, -6.3351, 530.8252, 56.2931, -6.3572, 529.2474, 56.1309, -6.3820, 527.9787, 56.0019, -6.4095, 527.0385, 55.9076, -6.4398, 526.4416, 55.8491, -6.4728, 526.1972, 55.8270, -6.5084, 526.3096, 55.8413, -6.5466, 526.7776, 55.8914, -6.5872, 527.5951, 55.9763, -6.6298, 528.7505, 56.0943, -6.6743, 530.2273, 56.2433, -6.7204, 532.0039, 56.4207, -6.7675, 534.0541, 56.6234, -6.8154, 536.3470, 56.8478, -6.8637, 538.8476, 57.0899, -6.9117, 541.5165, 57.3455, -6.9590, 544.3112, 57.6096, -7.0050, 547.1855, 57.8775, -7.0492, 550.0904, 58.1437, -7.0910, 552.9744, 58.4027, -7.1298, 555.7840, 58.6490, -7.1650, 558.4640, 58.8767, -7.1960, 560.9581, 59.0799, -7.2221, 563.2094, 59.2528, -7.2427, 565.1608, 59.3894, -7.2574, 566.7555, 59.4841, -7.2654, 567.9376, 59.5311, -7.2662, 568.6524, 59.5250, -7.2594, 568.8470, 59.4605, -7.2443, 568.4708, 59.3327, -7.2206, 567.4758, 59.1370, -7.1879, 565.8173, 58.8689, -7.1456, 563.4540, 58.5248, -7.0937, 560.3483, 58.1010, -7.0317, 556.4672, 57.5946, -6.9594, 551.7821, 57.0032, -6.8766, 546.2691, 56.3248, -6.7834, 539.9097, 55.5579, -6.6796, 532.6905, 54.7018, -6.5652, 524.6034, 53.7561, -6.4403, 515.6462, 52.7213, -6.3051, 505.8221, 51.5981, -6.1597, 495.1402, 50.3881, -6.0045, 483.6150, 49.0935, -5.8397, 471.2668, 47.7167, -5.6659, 458.1215, 46.2610, -5.4833, 444.2103, 44.7303, -5.2925, 429.5696, 43.1287, -5.0941, 414.2408, 41.4611, -4.8887, 398.2700, 39.7325, -4.6769, 381.7079, 37.9489, -4.4595, 364.6091, 36.1160, -4.2371, 347.0323, 34.2404, -4.0105, 329.0392, 32.3288, -3.7805, 310.6947, 30.3881, -3.5480, 292.0661, 28.4256, -3.3137, 273.2231, 26.4485, -3.0786, 254.2366, 24.4644, -2.8434, 235.1788, 22.4808, -2.6090, 216.1229, 20.5053, -2.3764, 197.1417, 18.5455, -2.1463, 178.3082, 16.6087, -1.9195, 159.6943, 14.7024, -1.6969, 141.3707, 12.8336, -1.4793, 123.4065, 11.0094, -1.2674, 105.8685, 9.2362, -1.0619, 88.8208, 7.5206, -0.8636, 72.3247, 5.8685, -0.6731, 56.4379, 4.2854, -0.4910, 41.2144, 2.7766, -0.3177, 26.7041, 1.3467, -0.1539, 12.9523};

int get_feature_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
LIS3DSH_InitTypeDef myAccConfigDef;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 CRC_HandleTypeDef hcrc;

SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_CRC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
    char *comma = ",";
	char *end = " \n";
	char *message[500] = {};
#include <stdarg.h>
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string, fmt, argp)) // build string
    {

    //HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 0xffffff); // send message via UART
    	 CDC_Transmit_FS((uint8_t*)string, strlen(string));
    }
}

void ei_printf(const char *format, ...) {
    va_list myargs;
    va_start(myargs, format);
    vprint(format, myargs);
    va_end(myargs);
}
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
  signal_t signal;
  signal.total_length = sizeof(features) / sizeof(features[0]);
  signal.get_data = &get_feature_data;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_SPI1_Init();
  MX_CRC_Init();
  /* USER CODE BEGIN 2 */
  myAccConfigDef.dataRate = LIS3DSH_DATARATE_25;
  	myAccConfigDef.fullScale = LIS3DSH_FULLSCALE_4;
  	myAccConfigDef.antiAliasingBW = LIS3DSH_FILTER_BW_50;//update rate
  	myAccConfigDef.enableAxes = LIS3DSH_XYZ_ENABLE;
  	myAccConfigDef.interruptEnable = false;
  	LIS3DSH_Init(&hspi1, &myAccConfigDef);
  	LIS3DSH_DataScaled myscaledata;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	while (1)
  	{
  	      ei_impulse_result_t result = { 0 };
  	      EI_IMPULSE_ERROR res = run_classifier(&signal, &result, true);
  	      ei_printf("run_classifier returned: %d\n", res);

  	      ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
  	          result.timing.dsp, result.timing.classification, result.timing.anomaly);

  	      // print the predictions
  	      ei_printf("[");
  	      for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
  	    	  ei_printf_float(result.classification[ix].value);
  	  #if EI_CLASSIFIER_HAS_ANOMALY == 1
  	          ei_printf(", ");
  	  #else
  	          if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
  	              ei_printf(", ");
  	          }
  	  #endif
  	      }
  	  #if EI_CLASSIFIER_HAS_ANOMALY == 1
  	      ei_printf_float(result.anomaly);
  	  #endif
  	      ei_printf("]\n\n\n");

  	    HAL_Delay(5000);
  	}
  }
  /* USER CODE END 3 */

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3|GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE3 PE0 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

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
