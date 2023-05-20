/*
 * lib_timer.c
 *
 *  Created on: 2023/05/20
 *      Author: RATTAN
 */

#include "lib_timer.h"

extern void toggle(void);
void LIB_TIMER_Init()//(uint8_t ISR_TIMER_Base, uint8_t ISR_TIMER_Part, )
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC_UP);
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()/1000 - 1);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    LIB_ISR_TIMERRegister(0, 0, toggle);
    IntEnable(INT_TIMER0A);
    IntMasterEnable();
    TimerEnable( TIMER0_BASE,  TIMER_A);
}
