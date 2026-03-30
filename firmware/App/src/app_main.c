#include "main.h"
#include "timing.h"

int main(void)
{
	mcuConfiguration();

	LL_SYSTICK_EnableIT();

	for(;;)
	{
		timing_waitForSysTick();
		LL_mDelay(50);
		LL_GPIO_TogglePin(ledBlue_GPIO_Port, ledBlue_Pin);
	}
}
