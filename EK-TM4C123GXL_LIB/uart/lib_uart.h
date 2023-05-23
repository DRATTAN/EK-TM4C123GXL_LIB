/*
 * lib_uart.h
 *
 *  Created on: 2023/05/21
 *      Author: RATTAN
 */

#ifndef EK_TM4C123GXL_LIB_UART_LIB_UART_H_
#define EK_TM4C123GXL_LIB_UART_LIB_UART_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_uart.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "lib_time.h"
#include "lib_uart_define.h"
#include "lib_isrmanagement.h"

void LIB_UART_Init(uint8_t, uint32_t, void (*)(void));

#endif /* EK_TM4C123GXL_LIB_UART_LIB_UART_H_ */
