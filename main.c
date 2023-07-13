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

#include "LIB_INCLUDE.h"
#include "PERI_INCLUDE.h"
void toggle(void);
void motor_control(void);

uint8_t buffer;
uint8_t temp[10] = {};
uint16_t i = 0;
uint8_t Adata[8];
int main(void)
{
    volatile uint32_t ui32Loop;
    IntMasterEnable();
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    LIB_UART_PrintfInit();
    LIB_I2C_Init(I2C0, 0);
    LIB_TIMER_InitCycle(TIMER5, 1, motor_control);
    LIB_TIMER_TimerEnable(TIMER5);
    while(1)
    {
        //Oled_ShowNumber(0, 1,VL53L0x_Bottom.distValid, 4);
        UARTprintf("duty:%d\n",VL53L0x_Bottom.distValid);
        //Hcsr04_GetDistance();
        delay_ms(100);
    }
}

void toggle()
{
    return ;
}
void motor_control()
{
    //Oled_ShowNumber(0, 1, 4);
    i++;
    if(i>1000) i = 0;
    //UARTprintf(" running \n");
}
