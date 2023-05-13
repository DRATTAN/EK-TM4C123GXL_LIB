/*EK-TM4C123GXL_LIB
 * ����:RATTAN
 * �ļ�����:none
 */

#include "lib_gpio.h"

/*
 * ����:��ʼ��GPIO�˿�
 * ����
 *  @Port:
 *      GPIO����ַ.����:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      �˿ں�,����:
 *          GPIO_PIN_0
 *  @Dir:
 *      ����,��������Ϊ:
 *          GPIO_DIR_OUTPUT     ���,
 *          GPIO_DIR_INPUT      ����
 *  @Type:
 *      �� ��/�� ����,��Pin����Ϊ����ʱ,��������Ϊ:
 *          GPIO_PIN_TYPE_INPUT_WPU     ������
 *          GPIO_PIN_TYPE_INPUT_WPD     ������
 *      ������PinΪ���ʱ,��������Ϊ:
 *          GPIO_PIN_TYPE_OUTPUT_STD    �������
 *          GPIO_PIN_TYPE_OUTPUT_OD     ��©���
 *  @Value:
 *      Ĭ�������ƽ,�� Dir Ϊ GPIO_DIR_OUTPUT ʱ��Ч,��������Ϊ:
 *          GPIO_PIN_SET        �ߵ�ƽ
 *          GPIO_PIN_RESET      �͵�ƽ
 *      �� Dir Ϊ GPIO_DIR_OUTPUT ʱ,�˲����ᱻ����,��������0x00
 *
 * ����ֵ:void
 * ��ע:����ͬʱ��ʼ�������ͬGPIOx�µĶ˿�,����
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
 * ����:��GPIO��PINд������(���õ�ƽ)
 * ����
 *  @Port:
 *      GPIO����ַ.����:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      �˿ں�,����:
 *          GPIO_PIN_0
 *  @Value:
 *      ���õĵ�ƽ,��������Ϊ:
 *      GPIO_PIN_SET        ����ߵ�ƽ
 *      GPIO_SET_RESET      ����͵�ƽ
 * ����ֵ:void
 * ��ע:����ͬʱ�����ͬGPIOx����˿��µ�Pin����ͬ��ѹ,����LIB_GPIO_WritePin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
 */
void LIB_GPIO_WritePin(uint32_t Port, uint32_t Pin, uint8_t Value)
{
    uint8_t reg = HWREG(Port + (GPIO_O_DATA + (Pin << 2)));
    if(GPIO_PIN_RESET == Value) HWREG(Port + (GPIO_O_DATA + (Pin << 2))) = (reg & ~(Pin));
    else if(GPIO_PIN_SET == Value) HWREG(Port + (GPIO_O_DATA + (Pin << 2))) = (reg | Pin);
    else return;
}


/*
 * ����:��ȡGPIO�˿���Pin�ĵ�ƽ
 * ����
 *  @Port:
 *      GPIO����ַ.����:
 *          GPIO_PORTA_AHB_BASE
 *  @Pin:
 *      �˿ں�,����:
 *          GPIO_PIN_0
 * ����ֵ:uint8_t
 *          ����ֵΪ��ȡ���ĵ�ƽ��ֵ.
 * ��ע:����ͬʱ��ȡ��ͬGPIOx�µĶ��Pin��ֵ,����LIB_GPIO_ReadPin(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);����ЩPin�����κ�
 * һ��ΪGPIO_PIN_SETʱ�򷵻�GPIO_PIN_SET,���򷵻�GPIO_PIN_RESET.����һ��ֻ��ȡһ��Pin
 */
uint8_t LIB_GPIO_ReadPin(uint32_t Port, uint32_t Pin)
{
    uint8_t reg = HWREG(Port + (GPIO_O_DATA + (Pin << 2))) & Pin;
    if(reg) return GPIO_PIN_SET;
    else return GPIO_PIN_RESET;
}
