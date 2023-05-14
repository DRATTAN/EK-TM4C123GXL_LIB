/*EK-TM4C123GXL_LIB
 * ����:RATTAN
 * �ļ�����:none
 */


#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "lib_gpio_define.h"
#include "lib_clock.h"
#include "lib_isrmanagement.h"

void LIB_GPIO_Init(uint32_t, uint8_t, uint8_t, uint32_t, uint8_t);
void LIB_GPIO_WritePin(uint32_t, uint32_t, uint8_t);
uint8_t LIB_GPIO_ReadPin(uint32_t, uint32_t);
void LIB_GPIO_TogglePin(uint32_t, uint32_t);
void LIB_GPIO_ExtiInit(uint8_t, uint8_t, uint8_t, void (*ISRISR_handler)(void));

#endif
