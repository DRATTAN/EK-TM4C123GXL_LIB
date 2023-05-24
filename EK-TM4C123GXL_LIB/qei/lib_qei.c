/*
 * lib_qei.c
 *
 *  Created on: 2023/05/24
 *      Author: RATTAN
 */

#include "lib_qei.h"

void LIB_QEI_Init()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI1);
    GPIOPinConfigure(GPIO_PC5_PHA1);                        //好多例程无这个函数
    //GPIOPinTypeQEI(GPIO_PORTC_BASE, GPIO_PIN_5);
    GPIOPinConfigure(GPIO_PC6_PHB1);
    GPIOPinTypeQEI(GPIO_PORTC_BASE, GPIO_PIN_5 | GPIO_PIN_6);
    GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_5 | GPIO_PIN_6, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);
    QEIConfigure(QEI1_BASE,(QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_NO_RESET | QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 0);
    QEIVelocityConfigure(QEI1_BASE, QEI_VELDIV_1, SysCtlClockGet()/10);
    QEIVelocityEnable(QEI1_BASE);
    QEIEnable(QEI1_BASE);
}

