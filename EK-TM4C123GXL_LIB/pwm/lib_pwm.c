/*
 * lib_pwm.c
 *
 *  Created on: 2023/05/26
 *      Author: RATTAN
 */

#include "lib_pwm.h"

/*
 * 描述:初始化PWM模块
 * 参数
 *  @PWm_Num:
 *      PWM 模块号 PWM_NUM_0 , PWM_NUM_1
 *  @PWM_Gen_Num:
 *      PWM 发生器号 PWM_Gen_Num_0 - PWM_Gen_Num_4
 *  @Freq:
 *      pwm频率 40 - 65535
 *  @dutyA:
 *      0通道初始占空比
 *  @dutyB:
 *      1通道初始占空比
 * 返回值:void
 * 备注:PWM满占空比为 2500,000/Freq
 */
void LIB_PWM_Init(uint8_t PWm_Num,uint8_t PWM_Gen_Num, uint32_t Freq, uint16_t dutyA,uint16_t dutyB)
{
    uint32_t GPIO_PORT_TABLE[2][4] = {{GPIO_PORTB_BASE, GPIO_PORTB_BASE, GPIO_PORTE_BASE, GPIO_PORTC_BASE},{GPIO_PORTD_BASE, GPIO_PORTA_BASE, GPIO_PORTF_BASE,GPIO_PORTF_BASE}};
    uint32_t GPIO_PIN_TABLE[2][4] = {{GPIO_PIN_6, GPIO_PIN_4, GPIO_PIN_4, GPIO_PIN_4},{GPIO_PIN_0, GPIO_PIN_6, GPIO_PIN_0, GPIO_PIN_2}};
    uint32_t GPIO_PERIPH_TABLE[2][4] = {{SYSCTL_PERIPH_GPIOB, SYSCTL_PERIPH_GPIOB, SYSCTL_PERIPH_GPIOE, SYSCTL_PERIPH_GPIOC},{SYSCTL_PERIPH_GPIOD, SYSCTL_PERIPH_GPIOA, SYSCTL_PERIPH_GPIOF,SYSCTL_PERIPH_GPIOF}};
    uint32_t GPIO_Px_MXPWMx_TABLE[2][4] = {{GPIO_PB6_M0PWM0, GPIO_PB4_M0PWM2, GPIO_PE4_M0PWM4, GPIO_PC4_M0PWM6},{GPIO_PD0_M1PWM0, GPIO_PA6_M1PWM2, GPIO_PF0_M1PWM4, GPIO_PF2_M1PWM6}};
    uint32_t PWM_OUT_TABLE[8] = {PWM_OUT_0, PWM_OUT_1, PWM_OUT_2, PWM_OUT_3, PWM_OUT_4, PWM_OUT_5, PWM_OUT_6, PWM_OUT_7};
    uint32_t PWM_OUT_BIT_TABLE[8] = {PWM_OUT_0_BIT, PWM_OUT_1_BIT, PWM_OUT_2_BIT, PWM_OUT_3_BIT, PWM_OUT_4_BIT, PWM_OUT_5_BIT, PWM_OUT_6_BIT, PWM_OUT_7_BIT};
    SysCtlPWMClockSet(SYSCTL_PWMDIV_32);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM_BASE + PWm_Num);
    SysCtlPeripheralEnable(GPIO_PERIPH_TABLE[PWm_Num][PWM_Gen_Num]);
    GPIOPinConfigure(GPIO_Px_MXPWMx_TABLE[PWm_Num][PWM_Gen_Num]);
    GPIOPinConfigure(GPIO_Px_MXPWMx_TABLE[PWm_Num][PWM_Gen_Num] + (0x00000004 << 8));
    GPIOPinTypePWM(GPIO_PORT_TABLE[PWm_Num][PWM_Gen_Num], GPIO_PIN_TABLE[PWm_Num][PWM_Gen_Num] | (GPIO_PIN_TABLE[PWm_Num][PWM_Gen_Num] << 1));
    PWMGenConfigure((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)), PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)), SysCtlClockGet() / 32 / Freq);
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)),PWM_OUT_TABLE[PWM_Gen_Num * 2],dutyA);
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)),PWM_OUT_TABLE[PWM_Gen_Num * 2 + 1],dutyB);
    PWMOutputState((PWM_BASE + (PWm_Num << 12)),PWM_OUT_BIT_TABLE[PWM_Gen_Num * 2],true);
    PWMOutputState((PWM_BASE + (PWm_Num << 12)),PWM_OUT_BIT_TABLE[PWM_Gen_Num * 2 + 1],true);
    PWMGenEnable((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)));
}

/*
 * 描述:设置占空比
 * 参数
 *  @PWm_Num:
 *      PWM 模块号 PWM_NUM_0 , PWM_NUM_1
 *  @PWM_Gen_Num:
 *      PWM 发生器号 PWM_Gen_Num_0 - PWM_Gen_Num_4
 *  @duty:
 *      占空比
 * 返回值:void
 * 备注:
 */
void LIB_PWM_SetPulseWidth(uint8_t PWm_Num, uint32_t PWM_Chanel_Base, uint16_t duty)
{
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)), PWM_Chanel_Base, duty);
}

