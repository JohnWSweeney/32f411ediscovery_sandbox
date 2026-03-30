/*============================================ Includes ==========================================*/

#include "main.h"
#include "ui.h"

/*============================================= Macros ===========================================*/

#define HEARTBEAT_DELAY			(500U)

/*======================================= Typedefs and Enums =====================================*/

typedef enum
{
	HEARTBEAT_BLUE = 0,
	HEARTBEAT_ORANGE,
	HEARTBEAT_GREEN,
	HEARTBEAT_RED
} HEARTBEAT_LED_PORT_t;

/*========================================= Private Data =========================================*/

static HEARTBEAT_LED_PORT_t heartbeat_led_port = HEARTBEAT_BLUE;

/*================================== Private Function Prototypes =================================*/

void ui_led_all_off(void);

/*======================================= Public Functions =======================================*/

/***************************************************************************************************
* x
***************************************************************************************************/
void set_heartbeat_blue(void)
{
	heartbeat_led_port = HEARTBEAT_BLUE;
}

/***************************************************************************************************
* x
***************************************************************************************************/
void ui_heartbeat(void)
{
	static uint16_t sysTick_cnt = 0U;

	if(sysTick_cnt != HEARTBEAT_DELAY)
	{
		sysTick_cnt++;
	}
	else
	{
		switch(heartbeat_led_port)
		{
			case HEARTBEAT_BLUE:
				LL_GPIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN);
				break;

			case HEARTBEAT_ORANGE:
				LL_GPIO_TogglePin(LED_ORANGE_PORT, LED_ORANGE_PIN);
				break;

			case HEARTBEAT_GREEN:
				LL_GPIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
				break;

			case HEARTBEAT_RED:
				LL_GPIO_TogglePin(LED_RED_PORT, LED_RED_PIN);
				break;

			default:
				break;
		}
		sysTick_cnt = 0U;
	}
}

/***************************************************************************************************
* x
***************************************************************************************************/
void ui_manage(void)
{
	ui_heartbeat();
}

/*======================================= Private Functions ======================================*/

/***************************************************************************************************
* x
***************************************************************************************************/
void ui_led_all_off(void)
{
	LL_GPIO_ResetOutputPin(LED_BLUE_PORT, LED_BLUE_PIN);
	LL_GPIO_ResetOutputPin(LED_ORANGE_PORT, LED_ORANGE_PIN);
	LL_GPIO_ResetOutputPin(LED_GREEN_PORT, LED_GREEN_PIN);
	LL_GPIO_ResetOutputPin(LED_RED_PORT, LED_RED_PIN);
}
