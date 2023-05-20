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

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************

void toggle(void);

//void LIB_TIMER_Init()
//{
//    //使能定时器TIMER0，16/32bit
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
//    //配置定时器，将定时器拆分，并配置拆分后的定时器A为周期性计数
//    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC_UP);
//    //设置定时器A装载值，因为要1ms进一次中断，所以1ms=1/1000
//    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()/1000 - 1);
//    //为定时器A注册中断函数
//    TimerIntRegister(TIMER0_BASE, TIMER_A, toggle);
//    //使能time0的定时器A为超时中断
//    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//    //设置中断优先级
//    //IntPrioritySet(INT_TIMER0A, 0);
//    //使能中断
//    IntEnable(INT_TIMER0A);
//    IntMasterEnable();
//    //使能定时器
//    TimerEnable(TIMER0_BASE, TIMER_A);
//}

int main(void)
{
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    volatile uint32_t ui32Loop;
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
    return ;
}
