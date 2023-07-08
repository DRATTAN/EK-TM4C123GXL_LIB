/*
 * oled.h
 *
 *  Created on: 2023/03/05
 *      Author: RATTAN
 */

#ifndef _OLED_H_
#define _OLED_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "front.h"
#include "lib_i2c.h"


#define Oled_Addr 0x78
#define I2C_NUM I2C0


uint32_t Oled_Pow(uint16_t, uint16_t);

void Oled_Cmd(uint8_t);
void Oled_Data(uint8_t);
void Oled_Datas(uint8_t*, uint32_t);
void Oled_Clear(void);
void Oled_Clear_Part(uint8_t, uint8_t, uint8_t);
void Oled_Init(void);
void Oled_Test(void);
void Oled_Fill(uint8_t);
void Oled_SetPos(uint8_t, uint8_t);
void Oled_ShowChar(uint8_t, uint8_t, char);
void Oled_ShowString(uint8_t, uint8_t, const char*);

void Oled_ShowNumber(uint8_t, uint8_t, int32_t, uint8_t);
void Oled_ShowParam(uint8_t, uint8_t, const char*, const int32_t, uint8_t);



#endif
