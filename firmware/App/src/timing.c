#include "timing.h"

static volatile uint8_t sysTick_flag = 0U;

void timing_sysTickISR(void)
{
	sysTick_flag = 1U;
}

void timing_waitForSysTick(void)
{
	while(sysTick_flag == 0U)
	{
		; // wait.
	}
	sysTick_flag = 0U;
}
