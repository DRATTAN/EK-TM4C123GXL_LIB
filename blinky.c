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
#include "vl53l0x.h"

void toggle(void);
void motor_control(void);

uint8_t buffer;
uint8_t temp[10] = {};
uint8_t i = 0;
int main(void)

{
    volatile uint32_t ui32Loop;
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    LIB_UART_PrintfInit();
    //LIB_TIMER_InitCycle(TIMER5, 1, motor_control);
    LIB_I2C_Init(I2C0, 1);
    IntMasterEnable();
    UARTprintf(" distance is:%u\n", Vl53l0x_GetDistance());
    while(1)
    {
//        Vl53l0x_ConvOnce();
//
//        delay_ms(100);
//
//        UARTprintf(" distance is: %u \n", VL53L0x_GetDistance());
//        delay_ms(500);
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
