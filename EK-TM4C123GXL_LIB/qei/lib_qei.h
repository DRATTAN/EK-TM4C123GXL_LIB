/*
 * lib_qei.h
 *
 *  Created on: 2023/05/24
 *      Author: RATTAN
 */

#ifndef EK_TM4C123GXL_LIB_QEI_LIB_QEI_H_
#define EK_TM4C123GXL_LIB_QEI_LIB_QEI_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#include "inc/tm4c123gh6pm.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"
#include "lib_qei_define.h"

void LIB_QEI_Init(void);
#endif /* EK_TM4C123GXL_LIB_QEI_LIB_QEI_H_ */
