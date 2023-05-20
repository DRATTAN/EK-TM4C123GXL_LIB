/*
 * timer.h
 *
 *  Created on: 2023/05/20
 *      Author: RATTAN
 */

#ifndef EK_TM4C123GXL_LIB_TIMER_LIB_TIMER_H_
#define EK_TM4C123GXL_LIB_TIMER_LIB_TIMER_H_

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/interrupt.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/timer.h"
#include "lib_isrmanagement.h"

void LIB_TIMER_Init(void);

#endif /* EK_TM4C123GXL_LIB_TIMER_LIB_TIMER_H_ */
