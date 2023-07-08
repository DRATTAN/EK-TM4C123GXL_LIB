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
#include "lib_pwm.h"
#include "lib_i2c.h"

#include "oled.h"

void toggle(void);
void motor_control(void);

uint8_t *buffer;

int main(void)

{
    volatile uint32_t ui32Loop;
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    LIB_UART_PrintfInit();
    //LIB_TIMER_InitCycle(TIMER5, 1, motor_control);
    LIB_I2C_Init(I2C0, 1);
    IntMasterEnable();

    Oled_Init();
    int8_t i = 0;
    while(1)
    {

        UARTprintf(" running \n");
        delay_ms(25);
        Oled_ShowParam(0, 0, "value", i, 4);
        i++;
    }
}

void toggle()
{

    return ;
}
void motor_control()
{
    UARTprintf(" running \n");
}
