#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"


#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"


#include "lib_clock.h"
#include "lib_gpio.h"
#include "lib_time.h"
#include "lib_timer.h"
#include "lib_uart.h"
#include "lib_qei.h"
#include "utils/uartstdio.h"

void toggle(void);
void QEI1_Isr_Handler(void);

uint8_t *buffer;

int main(void)

{
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    volatile uint32_t ui32Loop;
    LIB_GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIOF, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    //LIB_UART_Init(UART1, 115200, toggle);
    LIB_UART_PrintfInit();
    LIB_TIMER_InitCycle(TIMER0, 1, toggle);
    LIB_QEI_Init();
    LIB_TIMER_IntEnable(TIMER0);
    IntMasterEnable();
    while(1)
    {
        for(ui32Loop = 0; ui32Loop < 20000; ui32Loop++)
        {
        }
    }
}

void toggle()
{
    LIB_GPIO_TogglePin(GPIOF, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    LIB_GPIO_TogglePin(GPIOF, GPIO_PIN_5);
    return ;
}
void QEI1_Isr_Handler()
{
  QEIIntClear(QEI1_BASE, QEI_INTTIMER);
  uint32_t POS = QEIPositionGet(QEI1_BASE);
  int32_t d = QEIDirectionGet(QEI1_BASE);
  uint32_t COUNT = QEIVelocityGet(QEI1_BASE);
  uint32_t s = (COUNT * 6000) / 2024;
  UARTprintf("The Speed is %d .Velocity is %d.Direction is %d.\n",s,COUNT /4,d);
}
