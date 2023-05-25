/*
 * lib_timer.c
 *
 *  Created on: 2023/05/20
 *      Author: RATTAN
 */

#include "lib_timer.h"

/*
 * 描述:初始化周期定时器
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 *  @Freq:
 *      定时器中断触发频率
 *  @TIMER_ISRhandle:
 *      中断服务函数
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_InitCycle(uint8_t TIMERx, uint32_t Freq, void (*TIMER_ISRhandle)(void))
{
    uint32_t TIMER_INT_TABLE[6] = {INT_TIMER0A, INT_TIMER1A, INT_TIMER2A, INT_TIMER3A, INT_TIMER4A, INT_TIMER5A};
    SysCtlPeripheralEnable(TIMERx + SYSCTL_PERIPH_BASE);
    TimerDisable(((TIMERx << 12) + TIMER_BASE),TIMER_A);
    LIB_ISR_TIMERRegister(TIMERx, 0, TIMER_ISRhandle);
    TimerConfigure(((TIMERx << 12) + TIMER_BASE), TIMER_CFG_A_PERIODIC_UP);
    TimerLoadSet(((TIMERx << 12) + TIMER_BASE), TIMER_A, SysCtlClockGet()/Freq - 1);
    TimerIntEnable(((TIMERx << 12) + TIMER_BASE), TIMER_TIMA_TIMEOUT);
    IntEnable(TIMER_INT_TABLE[TIMERx]);
    TimerEnable(((TIMERx << 12) + TIMER_BASE),TIMER_A);
}

/*
 * 描述:失能定时器中断
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_IntDisable(uint8_t TIMERx)
{
    TimerIntDisable(((TIMERx << 12) + TIMER_BASE), TIMER_TIMA_TIMEOUT);
}
/*
 * 描述:使能定时器中断
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_IntEnable(uint8_t TIMERx)
{
    TimerIntEnable(((TIMERx << 12) + TIMER_BASE), TIMER_TIMA_TIMEOUT);
}

/*
 * 描述:设置定时器中断触发频率
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 *  @Freq:
 *      定定时器中断触发频率
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_SetFreq(uint8_t TIMERx, uint32_t Freq)
{
    TimerLoadSet(((TIMERx << 12) + TIMER_BASE), TIMER_A, SysCtlClockGet()/Freq - 1);
}

/*
 * 描述:失能定时器
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_TimerDisable(uint8_t TIMERx)
{
    TimerDisable(TIMER0_BASE,TIMER_A);
}

/*
 * 描述:使能定时器
 * 参数
 *  @TIMERx:
 *      定时器号
 *          TIMER0-TIMER5
 * 返回值:void
 * 备注:None
 */
void LIB_TIMER_TimerEnable(uint8_t TIMERx)
{
    TimerEnable(TIMER0_BASE,TIMER_A);
}
