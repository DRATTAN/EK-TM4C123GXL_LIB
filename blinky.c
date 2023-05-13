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
#include "lib_clock.h"
#include "lib_gpio.h"

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{

    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);

    volatile uint32_t ui32Loop;

    LIB_GPIO_Init(GPIO_PORTB_AHB_BASE, GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIO_PORTF_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIO_PORTF_AHB_BASE, GPIO_PIN_4, GPIO_DIR_INPUT, GPIO_PIN_TYPE_INPUT_WPU, GPIO_PIN_SET);

    while(1)
    {
        //
        // Turn on the LED.
        //
        LIB_GPIO_WritePin(GPIO_PORTF_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
        LIB_GPIO_WritePin(GPIO_PORTB_AHB_BASE,GPIO_PIN_5, GPIO_PIN_SET);
        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        //
        // Turn off the LED.
        //
        LIB_GPIO_WritePin(GPIO_PORTF_AHB_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);
        LIB_GPIO_WritePin(GPIO_PORTB_AHB_BASE, GPIO_PIN_5, GPIO_PIN_RESET);
        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
        if(LIB_GPIO_ReadPin(GPIO_PORTF_AHB_BASE, GPIO_PIN_4) == 0) LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_5M);
        else LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    }
}
