#include "main.h"

int main(void)
{
	mcuConfiguration();

	for(;;)
	{
		LL_mDelay(1000);
		LL_GPIO_TogglePin(ledBlue_GPIO_Port, ledBlue_Pin);
	}
}
