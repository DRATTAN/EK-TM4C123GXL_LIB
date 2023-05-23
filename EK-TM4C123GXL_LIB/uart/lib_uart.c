/*
 * lib_uart.c
 *
 *  Created on: 2023/05/21
 *      Author: RATTAN
 */

#include "lib_uart.h"

/*
 * 描述:初始化UARTx
 * 参数
 *  @Uart_Ver:
 *      串口号:
 *          UART0-UART7
 *          uart    rx      tx
 *          0       PA0     PA1
 *          1       PB0     PB1
 *          2       PD6     PD7
 *          3       PC6     PC7
 *          4       PC4     PC5
 *          5       PE4     PE5
 *          6       PD4     PD5
 *          7       PE0     PE1
 *  @Baud:
 *      波特率:
 *          典型值115200,9600,19200
 *  @UARTx_ISRhandle:
 *      串口接收回调函数:
 *          当不使用串口接收中断时,请仍创建一个函数填入,此函数中必须存在LIB_UART_Get(UARTx),否则串口会溢出
 * 返回值:void
 * 备注:
 */
void LIB_UART_Init(uint8_t Uart_Ver, uint32_t Baud, void (*UARTx_ISRhandle)(void))
{
    uint32_t INT_UART_TABLE[8] = {INT_UART0, INT_UART1, INT_UART2, INT_UART3, INT_UART4, INT_UART5, INT_UART6, INT_UART7};

    switch(Uart_Ver)
    {
    case UART0:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
        GPIOPinConfigure(GPIO_PA0_U0RX);
        GPIOPinConfigure(GPIO_PA1_U0TX);
        GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
    case UART1:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
        GPIOPinConfigure(GPIO_PB0_U1RX);
        GPIOPinConfigure(GPIO_PB1_U1TX);
        GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
    case UART2:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
        GPIOPinConfigure(GPIO_PD6_U2RX);
        GPIOPinConfigure(GPIO_PD7_U2TX);
        GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
        break;
    case UART3:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
        GPIOPinConfigure(GPIO_PC6_U3RX);
        GPIOPinConfigure(GPIO_PC7_U3TX);
        GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_6 | GPIO_PIN_7);
        break;
    case UART4:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
        GPIOPinConfigure(GPIO_PC4_U4RX);
        GPIOPinConfigure(GPIO_PC5_U4TX);
        GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        break;
    case UART5:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
        GPIOPinConfigure(GPIO_PE4_U5RX);
        GPIOPinConfigure(GPIO_PE5_U5TX);
        GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        break;
    case UART6:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
        GPIOPinConfigure(GPIO_PD4_U6RX);
        GPIOPinConfigure(GPIO_PD5_U6TX);
        GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        break;
    case UART7:
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
        while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
        GPIOPinConfigure(GPIO_PE0_U7RX);
        GPIOPinConfigure(GPIO_PE1_U7TX);
        GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
    }
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UARTBASE + Uart_Ver);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UARTBASE + Uart_Ver)) ;

    LIB_ISR_UARTRegister(Uart_Ver, UARTx_ISRhandle);
    UARTConfigSetExpClk((UART_BASE + (Uart_Ver<<12)), SysCtlClockGet(), Baud, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    IntEnable(INT_UART_TABLE[Uart_Ver]);
    UARTIntEnable((UART_BASE + (Uart_Ver<<12)), UART_INT_RX);
    UARTFIFODisable((UART_BASE + (Uart_Ver<<12)));
    return;
}

void LIB_UART_Put(uint8_t Uart_Ver, uint8_t Char)
{

}

void LIB_UART_Transmit(uint8_t Uart_Ver, uint8_t* Pointer)
{

}

uint8_t LIB_UART_Get(uint8_t Uart_Ver)
{

}
