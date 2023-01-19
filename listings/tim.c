#include "tim.h"
#include "tim_macros.h"

TIM_HandleTypeDef htim2;

/* TIM2 init function */
void MX_TIM2_Init(void)
{
  uint32_t tim2_prescaler;
  uint32_t tim2_period;

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* Set timer prescaler value (timer frequency) */
  /* Note: Value TIMER_FREQUENCY_RANGE_MAX_HZ with factor 2 to have a minimum
	 timer resolution */
  tim2_prescaler = __LL_TIM_CALC_PSC(SystemCoreClock,
		TIMER2_FREQUENCY_RANGE_MAX_HZ * 2);

  /* Set timer period value (time base frequency) */
  tim2_period = __LL_TIM_CALC_ARR(SystemCoreClock, tim2_prescaler,
	    TIMER2_FREQUENCY_HZ);
			
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = tim2_prescaler;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = tim2_period;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  if(tim_baseHandle->Instance==TIM2)
  {
    /* TIM2 clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 interrupt Init */
    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  }
}