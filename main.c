#include <stdint.h>
#include <stdbool.h>

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
    Cx20106a_Init();
    //LIB_TIMER_InitCycle(TIMER5, 1, motor_control);
    //LIB_TIMER_TimerEnable(TIMER5);
    //LIB_PWM_Init(PWM_NUM_0, PWM_GEN_NUM_0, 10000, 0,0);
    while(1)
    {
        UARTprintf("distance: %u \n", Cx20106a_GetDistance());
        i++;
        if(i == 250) i = 0;
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
