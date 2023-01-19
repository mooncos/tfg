#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/* Parameters of time base (used as ADC conversion trigger) */
/* Time base frequency (unit: Hz). With a timer 16 bits and time base       */
#define TIMER2_FREQUENCY_HZ              (250000U) // tested OK with 2e6
/* Time base range frequency maximum (unit: Hz).*/
/* With a timer 16 bits, minimum frequency will be 1/32000 times this value.*/
#define TIMER2_FREQUENCY_RANGE_MAX_HZ    (250000U) // tested OK with 2e6

extern TIM_HandleTypeDef htim2;

void MX_TIM2_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

