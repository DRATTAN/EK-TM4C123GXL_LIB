/*EK-TM4C123GXL_LIB
 * ����:RATTAN
 * �ļ�����:none
 */


#define GPIO_DIR_OUTPUT                 0x01
#define GPIO_DIR_INPUT                  0x00

#define GPIO_PIN_SET                    0x01
#define GPIO_PIN_RESET                  0x00
#define GPIO_PIN_TYPE_INPUT_WPU GPIO_PIN_TYPE_STD_WPU
#define GPIO_PIN_TYPE_INPUT_WPD GPIO_PIN_TYPE_STD_WPD
#define GPIO_PIN_TYPE_OUTPUT_STD    GPIO_PIN_TYPE_STD
#define GPIO_PIN_TYPE_OUTPUT_OD GPIO_PIN_TYPE_OD


#define GPIOAH   GPIO_PORTA_AHB_BASE
#define GPIOBH   GPIO_PORTB_AHB_BASE
#define GPIOCH   GPIO_PORTC_AHB_BASE
#define GPIODH   GPIO_PORTD_AHB_BASE
#define GPIOEH   GPIO_PORTE_AHB_BASE
#define GPIOFH   GPIO_PORTF_AHB_BASE

#define GPIOA   GPIO_PORTA_BASE
#define GPIOB   GPIO_PORTB_BASE
#define GPIOC   GPIO_PORTC_BASE
#define GPIOD   GPIO_PORTD_BASE
#define GPIOE   GPIO_PORTE_BASE
#define GPIOF   GPIO_PORTF_BASE

#define GPIO_EXTI_TRIGGER_RISING 0x00
#define GPIO_EXTI_TRIGGER_FALLING 0x01
#define GPIO_EXTI_TRIGGER_BOTHEDGES 0x02
#define GPIO_EXTI_TRIGGER_HIGH 0x03
#define GPIO_EXTI_TRIGGER_LOW 0x04
#define GPIO_EXTI_TRIGGER_DISCRETE_INT 0x05
