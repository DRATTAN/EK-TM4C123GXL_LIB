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

int main(void)
{
    volatile uint32_t ui32Loop;
    IntMasterEnable();
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    LIB_UART_PrintfInit();
    LIB_I2C_Init(I2C0, 1);
    Photocell_Check();
    Oled_Init();
    LIB_TIMER_InitCycle(TIMER5, 100, motor_control);
    LIB_TIMER_TimerEnable(TIMER5);
    Hcsr04_Init(ISR_GPIOB, ISR_GPIO_PIN_4, GPIOB, GPIO_PIN_5);
    LIB_PWM_Init(PWM_NUM_0, PWM_GEN_NUM_0, 10000, 500, 100);
    LIB_PWM_SetPulseWidth(PWM_NUM_0, PWM_CHANNEL_0, 800);
    LIB_PWM_SetPulseWidth(PWM_NUM_0, PWM_CHANNEL_1, 800);
    Oled_ShowNumber(0, 0,Photocell_Check(), 2);
    while(1)
    {
        //UARTprintf("duty:%d\n",i);
        //Hcsr04_GetDistance();
        delay_ms(10);
    }
}

void toggle()
{
    return ;
}
void motor_control()
{
    Oled_ShowNumber(0, 1,Photocell_ReadValue(), 4);
    i++;
    if(i>1000) i = 0;
    //UARTprintf(" running \n");
}
