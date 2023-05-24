#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"


#include "driverlib/interrupt.h"
#include "inc/tm4c123gh6pm.h"

#include "lib_clock.h"
#include "lib_gpio.h"
#include "lib_time.h"
#include "lib_timer.h"
#include "lib_uart.h"


void toggle(void);
uint8_t *buffer;

int main(void)
{
    LIB_CLOCK_MainClockSet(CLOCK_XTAL_PLL_80M);
    volatile uint32_t ui32Loop;
    LIB_UART_Init(UART0, 512000, toggle);
    LIB_GPIO_Init(GPIOBH, GPIO_PIN_5, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_GPIO_Init(GPIOFH, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_RESET);
    LIB_TIMER_Init();
    while(1)
    {
        for(ui32Loop = 0; ui32Loop < 20000; ui32Loop++)
        {
        }
    }
}

void toggle()
{

    LIB_GPIO_TogglePin(GPIOFH, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    LIB_GPIO_TogglePin(GPIOFH, GPIO_PIN_5);
    return ;
}
