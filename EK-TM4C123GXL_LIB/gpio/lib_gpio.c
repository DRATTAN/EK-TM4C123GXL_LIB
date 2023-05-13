/*EK-TM4C123GXL_LIB
 * 作者:RATTAN
 * 文件描述:none
 */

#include "lib_gpio.h"

/*
 * 描述:初始换GPIO端口
 * 参数
 *  @Port:
 *      GPIO基地址.例如:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      端口号,例如:
 *          GPIO_PIN_0
 *  @Dir:
 *      方向,可以设置为:
 *          GPIO_DIR_OUTPUT     输出,
 *          GPIO_DIR_INPUT      输入
 *  @Type:
 *      输 入/出 配置,当Pin配置为输入时,可以配置为:
 *          GPIO_PIN_TYPE_INPUT_WPU     弱上拉
 *          GPIO_PIN_TYPE_INPUT_WPD     若下拉
 *      当配置Pin为输出时,可以配置为:
 *          GPIO_PIN_TYPE_OUTPUT_STD    推挽输出
 *          GPIO_PIN_TYPE_OUTPUT_OD     开漏输出
 *  @Value:
 *      默认输出电平,仅 Dir 为 GPIO_DIR_OUTPUT 时有效,可以配置为:
 *          GPIO_PIN_SET        高电平
 *          GPIO_PIN_RESET      低电平
 *      当 Dir 为 GPIO_DIR_OUTPUT 时,此参数会被忽略,建议填入0x00
 *
 * 返回值:void
 * 备注:可以同时初始化多个相同GPIOx下的端口,例如
 * LIB_GPIO_Init(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_DIR_OUTPUT, GPIO_PIN_TYPE_OUTPUT_STD, GPIO_PIN_SET);
 */
void LIB_GPIO_Init(uint32_t Port, uint8_t Pin, uint8_t Dir, uint32_t Type, uint8_t Value)
{
    switch(Port)
    {
    case GPIO_PORTA_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOA);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOA);
        break;
    case GPIO_PORTB_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOB);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOB);
        break;
    case GPIO_PORTC_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOC);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOC);
        break;
    case GPIO_PORTD_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOD);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOD);
        break;
    case GPIO_PORTE_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOE);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOE);
        break;
    case GPIO_PORTF_AHB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOF);
        SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOF);
        break;
    case GPIO_PORTA_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOA);
        break;
    case GPIO_PORTB_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOB);
        break;
    case GPIO_PORTC_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOC);
        break;
    case GPIO_PORTD_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOD);
        break;
    case GPIO_PORTE_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOE);
        break;
    case GPIO_PORTF_BASE:
        LIB_CLOCK_PeripheralClockEnable(SYSCTL_PERIPH_GPIOF);
        break;
    default: break;
    }

    if(GPIO_DIR_OUTPUT == Dir)
    {
        LIB_GPIO_WritePin(Port, Pin, Value);
        GPIOPadConfigSet(Port, Pin, GPIO_STRENGTH_2MA, Type);
        HWREG(Port + GPIO_O_DIR) = ((GPIO_DIR_MODE_OUT & 1) ? (HWREG(Port + GPIO_O_DIR) | Pin) : (HWREG(Port + GPIO_O_DIR) & ~(Pin)));
        HWREG(GPIO_DIR_MODE_OUT + GPIO_O_AFSEL) = ((GPIO_DIR_MODE_OUT & 2) ? (HWREG(Port + GPIO_O_AFSEL) | Pin) : (HWREG(Port + GPIO_O_AFSEL) & ~(Pin)));
    }

    else if(GPIO_DIR_INPUT == Dir)
    {
        HWREG(GPIO_DIR_MODE_IN + GPIO_O_DIR) = ((GPIO_DIR_MODE_IN & 1) ? (HWREG(Port + GPIO_O_DIR) | Pin) : (HWREG(Port + GPIO_O_DIR) & ~(Pin)));
        HWREG(GPIO_DIR_MODE_IN + GPIO_O_AFSEL) = ((GPIO_DIR_MODE_IN & 2) ? (HWREG(Port + GPIO_O_AFSEL) | Pin) : (HWREG(Port + GPIO_O_AFSEL) & ~(Pin)));
        GPIOPadConfigSet(Port, Pin, GPIO_STRENGTH_2MA, Type);
    }

    else return ;
}

/*
 * 描述:对GPIO的PIN写入数据(设置电平)
 * 参数
 *  @Port:
 *      GPIO基地址.例如:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      端口号,例如:
 *          GPIO_PIN_0
 *  @Value:
 *      设置的电平,可以配置为:
 *      GPIO_PIN_SET        输出高电平
 *      GPIO_SET_RESET      输出低电平
 * 返回值:void
 * 备注:可以同时输出相同GPIOx多个端口下的Pin于相同电压,例如LIB_GPIO_WritePin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
 */
void LIB_GPIO_WritePin(uint32_t Port, uint32_t Pin, uint8_t Value)
{
    uint8_t reg = HWREG(Port + (GPIO_O_DATA + (Pin << 2)));
    if(GPIO_PIN_RESET == Value) HWREG(Port + (GPIO_O_DATA + (Pin << 2))) = (reg & ~(Pin));
    else if(GPIO_PIN_SET == Value) HWREG(Port + (GPIO_O_DATA + (Pin << 2))) = (reg | Pin);
    else return;
}


/*
 * 描述:读取GPIO端口先Pin的电平
 * 参数
 *  @Port:
 *      GPIO基地址.例如:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      端口号,例如:
 *          GPIO_PIN_0
 * 返回值:uint8_t
 *          返回值为读取到的电平的值.
 * 备注:可以同时读取相同GPIOx下的多个Pin的值,例如LIB_GPIO_ReadPin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);当这些Pin中有任何
 * 一个为GPIO_PIN_SET时则返回GPIO_PIN_SET,否则返回GPIO_PIN_RESET.建议一次只读取一个Pin
 */
uint8_t LIB_GPIO_ReadPin(uint32_t Port, uint32_t Pin)
{
    uint8_t reg = HWREG(Port + (GPIO_O_DATA + (Pin << 2))) & Pin;
    if(reg) return GPIO_PIN_SET;
    else return GPIO_PIN_RESET;
}
