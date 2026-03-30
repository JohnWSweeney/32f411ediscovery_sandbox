#ifndef INC_TIMING_H_
#define INC_TIMING_H_

#include <stdint.h>


void timing_sysTickISR(void);

void timing_waitForSysTick(void);

#endif /* INC_TIMING_H_ */
