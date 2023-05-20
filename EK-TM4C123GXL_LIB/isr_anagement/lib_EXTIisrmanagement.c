#include "lib_isrmanagement.h"


void (* volatile ExtiIsrHandleTable[6][8])(void) =
{
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
 {__nop, __nop, __nop, __nop, __nop, __nop, __nop, __nop},
};

void GPIOA_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIOAH, true);
    GPIOIntClear(GPIOAH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 0, 7)();
}

void GPIOB_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIOBH, true);
    GPIOIntClear(GPIOBH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 1, 7)();
}
void GPIOC_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIOCH, true);
    GPIOIntClear(GPIOCH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 2, 7)();
}
void GPIOD_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIODH, true);
    GPIOIntClear(GPIODH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 3, 7)();
}
void GPIOE_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIOEH, true);
    GPIOIntClear(GPIOEH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 4, 7)();
}
void GPIOF_ISR_Handle(void)
{
    uint32_t status = GPIOIntStatus(GPIOFH, true);
    GPIOIntClear(GPIOFH, status);
    if((status & GPIO_PIN_0) == GPIO_PIN_0)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 0)();
    if((status & GPIO_PIN_1) == GPIO_PIN_1)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 1)();
    if((status & GPIO_PIN_2) == GPIO_PIN_2)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 2)();
    if((status & GPIO_PIN_3) == GPIO_PIN_3)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 3)();
    if((status & GPIO_PIN_4) == GPIO_PIN_4)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 4)();
    if((status & GPIO_PIN_5) == GPIO_PIN_5)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 5)();
    if((status & GPIO_PIN_6) == GPIO_PIN_6)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 6)();
    if((status & GPIO_PIN_7) == GPIO_PIN_7)    ACCESS_ISR_TABLE(ExtiIsrHandleTable, 5, 7)();
}

void LIB_ISR_GPIOEXTIISRInit()
{
    GPIOIntRegister(GPIOAH, GPIOA_ISR_Handle);
    GPIOIntRegister(GPIOBH, GPIOB_ISR_Handle);
    GPIOIntRegister(GPIOCH, GPIOC_ISR_Handle);
    GPIOIntRegister(GPIODH, GPIOD_ISR_Handle);
    GPIOIntRegister(GPIOEH, GPIOE_ISR_Handle);
    GPIOIntRegister(GPIOFH, GPIOF_ISR_Handle);
}

void LIB_ISR_GPIOEXTIRegister(uint8_t ISRGPIOPort, uint8_t ISRGPIOPin, void (*ISR_handler)(void))
{
    ExtiIsrHandleTable[ISRGPIOPort][ISRGPIOPin] = ISR_handler;
    return ;
}

void __nop()
{
    return;
}
