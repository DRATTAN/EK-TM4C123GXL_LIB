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
#include "hc-sr04.h"

void toggle(void);
void motor_control(void);

uint8_t buffer;
uint8_t temp[10] = {};
uint16_t i = 0;

int main(void)
{
    volatile uint32_t ui32Loop;
    IntMasterEnable();
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    LIB_UART_PrintfInit();
    //LIB_TIMER_InitCycle(TIMER5, 1, motor_control);
    //LIB_I2C_Init(I2C0, 1);
    LIB_PWM_Init(PWM_NUM_0, PWM_GEN_NUM_0, 10000,0, 0) ;
    LIB_PWM_SetPulseWidth(PWM_NUM_0, PWM_CHANNEL_0,10);
    LIB_PWM_SetPulseWidth(PWM_NUM_0, PWM_CHANNEL_1,500);
    while(1)
    {
        LIB_PWM_SetPulseWidth(PWM_NUM_0, PWM_CHANNEL_0,i);
        UARTprintf("duty:%d\n",i);
        delay_ms(1);
        if(i>998) i = 0;
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
