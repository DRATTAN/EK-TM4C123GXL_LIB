#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/tm4c123gh6pm.h"


#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"

#include "utils/uartstdio.h"

#include "lib_clock.h"
#include "lib_gpio.h"
#include "lib_time.h"
#include "lib_timer.h"
#include "lib_uart.h"
#include "lib_qei.h"


void toggle(void);
void motor_control(void);

uint8_t *buffer;

int main(void)

{
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    volatile uint32_t ui32Loop;
    LIB_GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIOF, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    //LIB_UART_Init(UART1, 115200, toggle);
    LIB_UART_PrintfInit();
    LIB_TIMER_InitCycle(TIMER0, 2, toggle);
    LIB_QEI_Init(QEI0, 200, motor_control);
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
void motor_control()
{
  UARTprintf("Velocity is %d    Direction is %d\n", (LIB_QEI_GetPulse(QEI0) / 4), LIB_QEI_GetDirect(QEI0));
}
