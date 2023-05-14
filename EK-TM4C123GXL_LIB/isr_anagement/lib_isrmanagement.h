#ifndef __LIB_ISRMANAGEMENT_H
#define __LIB_ISRMANAGEMENT_H

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/interrupt.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "lib_gpio.h"
#include "lib_isrmanagement_define.h"


void LIB_ISR_GPIOEXTIISRInit(void);

void LIB_ISR_GPIOEXTIRegister(uint8_t ISRGPIOPort, uint8_t ISRGPIOPin, void (*ISRISR_handler)(void));

#endif
