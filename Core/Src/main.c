#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "GPIO_HAL.h"
#include "Timmer_HAL.h"

#define LED_DELAY_MS (100U)

void SystemClock_Config(void);

/* Timer object */
TIMER_HAL Timer =
{
	&htim2,
	0U
};

/* LED PA5 */
GPIO_HAL LED =
{
	GPIOA,
	GPIO_PIN_5
};

/* LED PA6 */
GPIO_HAL LED1 =
{
	GPIOA,
	GPIO_PIN_6
};

/* LED PA7 */
GPIO_HAL LED2 =
{
	GPIOA,
	GPIO_PIN_7
};
GPIO_HAL LED3 =
{
	GPIOB,
	GPIO_PIN_0
};
GPIO_HAL LED4 =
{
	GPIOB,
	GPIO_PIN_1
};
GPIO_HAL LED5 =
{
	GPIOB,
	GPIO_PIN_2
};
GPIO_HAL LED6 =
{
	GPIOB,
	GPIO_PIN_10
};
GPIO_HAL LED7 =
{
	GPIOB,
	GPIO_PIN_11
};

int main(void)
{
    uint32_t startTick;
    uint8_t i;
    uint8_t j;

    /* Initialize HAL */
    HAL_Init();

    /* Configure system clock */
    SystemClock_Config();

    /* Initialize Timer */
    MX_TIM2_Init();

    /* Initialize LEDs */
    LED_Init(&LED);
    LED_Init(&LED1);
    LED_Init(&LED2);
    LED_Init(&LED3);
    LED_Init(&LED4);
    LED_Init(&LED5);
    LED_Init(&LED6);
    LED_Init(&LED7);

    /* Initialize timer */
    TIMER_Init(&Timer);

    /* Start timer */
    TIMER_Start(&Timer);

    /* LED array */
    GPIO_HAL *leds[8] =
    {
        &LED,
        &LED1,
        &LED2,
        &LED3,
        &LED4,
        &LED5,
        &LED6,
        &LED7
    };

    /* All LEDs OFF */
    for (i = 0U; i < 8U; i++)
    {
        LED_Off(leds[i]);
    }

    while (1)
    {
        /*========================================
         * Forward: LED1 -> LED7
         *========================================*/
        for (i = 0U; i < 8U; i++)
        {
            /* Turn all LEDs OFF */
            for (j = 0U; j < 8U; j++)
            {
                LED_Off(leds[j]);
            }

            /* Turn current LED ON */
            LED_On(leds[i]);

            /* Wait */
            startTick = TIMER_GetTick(&Timer);

            while (TIMER_IsElapsed(&Timer,
                                   startTick,
                                   LED_DELAY_MS) == 0U)
            {
                /* Wait */
            }
        }

        /*========================================
         * Reverse: LED6 -> LED1
         *========================================*/
        for (i = 6U; i > 0U; i--)
        {
            /* Turn all LEDs OFF */
            for (j = 0U; j < 8U; j++)
            {
                LED_Off(leds[j]);
            }

            /* Turn current LED ON */
            LED_On(leds[i]);

            /* Wait */
            startTick = TIMER_GetTick(&Timer);

            while (TIMER_IsElapsed(&Timer,
                                   startTick,
                                   LED_DELAY_MS) == 0U)
            {
                /* Wait */
            }
        }
    }
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
#ifdef USE_FULL_ASSERT
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
