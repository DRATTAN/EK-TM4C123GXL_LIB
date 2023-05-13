/*EK-TM4C123GXL_LIB
 * 作者:RATTAN
 * 文件描述:none
 */

#ifndef __CLOCK_H
#define __CLOCK_H

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "lib_clock_Define.h"

void LIB_CLOCK_MainClockSet(uint32_t);
void LIB_CLOCK_PeripheralClockEnable(uint32_t);
void LIB_CLOCK_PeripheralClockDisable(uint32_t);

#endif
