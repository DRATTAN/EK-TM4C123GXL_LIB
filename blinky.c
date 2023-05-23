//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.2.0.295 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"


#include "driverlib/interrupt.h"
#include "inc/tm4c123gh6pm.h"

#include "lib_clock.h"
#include "lib_gpio.h"
#include "lib_time.h"
#include "lib_timer.h"
#include "lib_uart.h"


void toggle(void);

int main(void)
{
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    volatile uint32_t ui32Loop;
    LIB_UART_Init(UART0, 9600, toggle);
    LIB_GPIO_Init(GPIOBH, GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIOFH, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_TIMER_Init();
    while(1)
    {
        for(ui32Loop = 0; ui32Loop < 20000; ui32Loop++)
        {
        }
    }
}

void toggle()
{
    LIB_GPIO_TogglePin(GPIOFH, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    LIB_GPIO_TogglePin(GPIOFH, GPIO_PIN_5);
    UARTCharGet(UART0_BASE);
    UARTCharPut(UART0_BASE, 'a');
    return ;
}
