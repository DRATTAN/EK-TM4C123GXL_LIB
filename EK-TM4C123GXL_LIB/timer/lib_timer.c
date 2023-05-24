/*
 * lib_timer.c
 *
 *  Created on: 2023/05/20
 *      Author: RATTAN
 */

#include "lib_timer.h"


void LIB_TIMER_InitCycle(uint8_t TIMERx, uint32_t Freq, void (*TIMER_ISRhandle)(void))
{
    uint32_t TIMER_INT_TABLE[6] = {INT_TIMER0A, INT_TIMER1A, INT_TIMER2A, INT_TIMER3A, INT_TIMER4A, INT_TIMER5A};
    SysCtlPeripheralEnable(TIMERx + SYSCTL_PERIPH_BASE);
    TimerConfigure(((TIMERx << 12) + TIMER_BASE), TIMER_CFG_A_PERIODIC_UP);
    TimerLoadSet(((TIMERx << 12) + TIMER_BASE), TIMER_A, SysCtlClockGet()/Freq - 1);
    TimerIntEnable(((TIMERx << 12) + TIMER_BASE), TIMER_TIMA_TIMEOUT);
    LIB_ISR_TIMERRegister(TIMERx, 0, TIMER_ISRhandle);
    IntEnable(TIMER_INT_TABLE[TIMERx]);
}

void LIB_TIMER_IntDisable(uint8_t TIMERx)
{
    TimerDisable(((TIMERx << 12) + TIMER_BASE), TIMER_A);
}

void LIB_TIMER_IntEnable(uint8_t TIMERx)
{
    TimerEnable(((TIMERx << 12) + TIMER_BASE), TIMER_A);
}

void LIB_TIMER_SetFreq(uint8_t TIMERx, uint32_t Freq)
{
    TimerLoadSet(((TIMERx << 12) + TIMER_BASE), TIMER_A, SysCtlClockGet()/Freq - 1);
}



