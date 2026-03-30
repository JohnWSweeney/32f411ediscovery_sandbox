
/*============================================ Includes ==========================================*/

#include "main.h"
#include "timing.h"
#include "ui.h"

/*======================================= Public Functions =======================================*/

int main(void)
{
	mcuConfiguration();

	for(;;)
	{
		timing_waitForSysTick();

		ui_manage();
	}
}
