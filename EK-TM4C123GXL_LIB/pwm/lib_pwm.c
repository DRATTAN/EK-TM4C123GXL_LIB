/*
 * lib_pwm.c
 *
 *  Created on: 2023/05/26
 *      Author: RATTAN
 */

#include "lib_pwm.h"

#define LIB_PWM_Gen_Perio_Table_Set(PWm_Num, PWM_Chanel_Base, Freq) GEN_PERIO_TABLE[PWm_Num][PWM_Chanel_Base/2] = Freq
#define LIB_PWM_Gen_Perio_Table_Get(PWm_Num, PWM_Chanel_Base) GEN_PERIO_TABLE[PWm_Num][PWM_Chanel_Base/2]

const uint32_t PWM_OUT_TABLE[8] = {PWM_OUT_0, PWM_OUT_1, PWM_OUT_2, PWM_OUT_3, PWM_OUT_4, PWM_OUT_5, PWM_OUT_6, PWM_OUT_7};

uint32_t GEN_PERIO_TABLE[2][4]= {{0, 0, 0, 0},{0, 0, 0, 0}};


/*
 * 描述:初始化PWM模块
 * PWM_NUM  PWM_CHANNEL     PIN
 *      0       0           B6
 *      0       1           B7
 *      0       2           B4
 *      0       3           B5
 *      0       4           E4
 *      0       5           E5
 *      0       6           C4
 *      0       7           C5
 *
 *      1       0           D0
 *      1       1           D1
 *      1       2           A6
 *      1       3           A7
 *      1       4           F0
 *      1       5           F1
 *      1       6           F2
 *      1       7           F3
 *
 * 参数
 *  @PWm_Num:
 *      PWM 模块号 PWM_NUM_0 , PWM_NUM_1
 *  @PWM_Gen_Num:
 *      PWM 发生器号 PWM_GEN_NUM_0 - PWM_GEN_NUM_4
 *  @Freq:
 *      pwm频率 40 - 65535
 *  @dutyA:
 *      A通道初始占空比
 *  @dutyB:
 *      B通道初始占空比
 * 返回值:void
 * 备注:PWM满占空比为 1000
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
    PWMGenConfigure((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)),PWM_GEN_MODE_UP_DOWN);
    LIB_PWM_Gen_Perio_Table_Set(PWm_Num, PWM_Gen_Num*2, SysCtlClockGet() / 32 / Freq - 1);
    PWMGenPeriodSet((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)), LIB_PWM_Gen_Perio_Table_Get(PWm_Num, PWM_Gen_Num));
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)),PWM_OUT_TABLE[PWM_Gen_Num * 2], (float)LIB_PWM_Gen_Perio_Table_Get(PWm_Num, PWM_Gen_Num) * ((float)dutyA / 1000.0));
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)),PWM_OUT_TABLE[PWM_Gen_Num * 2 + 1], (float)LIB_PWM_Gen_Perio_Table_Get(PWm_Num, PWM_Gen_Num) * ((float)dutyB / 1000.0));
    PWMOutputState((PWM_BASE + (PWm_Num << 12)),PWM_OUT_BIT_TABLE[PWM_Gen_Num * 2],true);
    PWMOutputState((PWM_BASE + (PWm_Num << 12)),PWM_OUT_BIT_TABLE[PWM_Gen_Num * 2 + 1],true);
    PWMGenEnable((PWM_BASE + (PWm_Num << 12)), (PWM_GEN_BASE + ((0x00000004 * PWM_Gen_Num) << 4)));
}

/*
 * 描述:设置占空比
 * 参数
 *  @PWm_Num:
 *      PWM 模块号 PWM_NUM_0 , PWM_NUM_1
 *  @PWM_Channel_Num:
 *      PWM 通道号 PWM_CHANNEL_0 - PWM_CHANNEL_7
 *  @duty:
 *      占空比
 * 返回值:void
 * 备注: PWM满占空比为 1000
 */
void LIB_PWM_SetPulseWidth(uint8_t PWm_Num, uint8_t PWM_Channel_Num,uint16_t duty)
{
    PWMPulseWidthSet((PWM_BASE + (PWm_Num << 12)), PWM_OUT_TABLE[PWM_Channel_Num], (float)LIB_PWM_Gen_Perio_Table_Get(PWm_Num, PWM_Channel_Num) * ((float)duty / 1000.0));
}

