/*
 * oled.c
 *
 *  Created on: 2023/03/05
 *      Author: RATTAN
 */



#include "oled.h"
#include <string.h>
#include <stdlib.h>

void Oled_Cmd(uint8_t cmd)
{
    LIB_I2C_Send(I2C_NUM, Oled_Addr >> 1, 0x00, cmd);
}

void Oled_Data(uint8_t data)
{
    LIB_I2C_Send(I2C_NUM, Oled_Addr >> 1, 0x40, data);
}

void Oled_Datas(uint8_t* pdata, uint32_t counter)
{
    LIB_I2C_Transmit(I2C_NUM, Oled_Addr >> 1, 0x40, pdata, counter);
}

void Oled_Test()
{
    Oled_Clear();
}

void Oled_Init()
{
    Oled_Cmd(0xae); Oled_Cmd(0x00); Oled_Cmd(0x10); Oled_Cmd(0x40); Oled_Cmd(0x81); Oled_Cmd(0xcf); Oled_Cmd(0xa1);
    Oled_Cmd(0xc8); Oled_Cmd(0xa6); Oled_Cmd(0xa8); Oled_Cmd(0x3f); Oled_Cmd(0xd3); Oled_Cmd(0x00); Oled_Cmd(0xd5);
    Oled_Cmd(0x80); Oled_Cmd(0xd9); Oled_Cmd(0xf1); Oled_Cmd(0xda); Oled_Cmd(0x12); Oled_Cmd(0xdb); Oled_Cmd(0x40);
    Oled_Cmd(0x20); Oled_Cmd(0x02); Oled_Cmd(0x8d); Oled_Cmd(0x14); Oled_Cmd(0xa4); Oled_Cmd(0xa6); Oled_Cmd(0xaf);
    Oled_Clear();  
}

void Oled_Clear()
{
    Oled_Fill(0x00);
}

void Oled_Clear_Part(uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t i = 0;
    Oled_Cmd(0xb0+y);
    Oled_Cmd(((x&0xf0)>>4)|0x10);
    Oled_Cmd((x&0x0f)|0x01);
    for (i = 0; i < length; i++) Oled_Datas((uint8_t*)F6x8[0], 6);
}

/// @brief 鏍煎紡濉厖
/// @param Data 濉厖鏁版嵁
void Oled_Fill(uint8_t Data)
{
    uint8_t m;
    uint8_t dis_buffer[128];
    for(m=0;m<128;m++) dis_buffer[m]=Data;
    for(m=0;m<8;m++)
    {
        Oled_Cmd(0xb0+m);
        Oled_Datas(dis_buffer, 128);
    }
}

/// @brief 璁剧疆鐐�
/// @param x 妯潗鏍�
/// @param y 绾靛潗鏍�
void Oled_SetPos(uint8_t x, uint8_t y)
{
    Oled_Cmd(0xb0+y);
    Oled_Cmd(((x&0xf0)>>4)|0x10);
    Oled_Cmd((x&0x0f)|0x01);
}

/// @brief 鏄剧ず鍗曚釜瀛楃
/// @param x 瀛楃妯潗鏍�
/// @param y 瀛楃绾靛潗鏍�
/// @param c 寰呮樉绀虹殑瀛楃
void Oled_ShowChar(uint8_t x, uint8_t y, char c)
{
    if(x>127 || y>7) return;
    Oled_SetPos(x,y);
    Oled_Datas((uint8_t*)F6x8[(uint8_t)(c-32)], 6);
}

/// @brief 鏄剧ず瀛楃涓�
/// @param x 瀛楃涓叉í鍧愭爣
/// @param y 瀛楃涓茬旱鍧愭爣
/// @param String_Addr 寰呮樉绀虹殑瀛楃涓�
void Oled_ShowString(uint8_t x, uint8_t y, const char* String_Addr)
{
    uint8_t lenth=strlen(String_Addr),i=0;
    int16_t j=x;
    Oled_SetPos(x,y);
    for(i=0;i<lenth;i++)
    {
        j+=6;
        if(((int16_t)127-j<=(int16_t)0) || (*(String_Addr+i) == 0x00))
        {
            return;
        }
        Oled_Datas((uint8_t*)F6x8[(uint8_t)(*(String_Addr+i)-32)], 6);
    }
}

void Oled_ShowNumberBase(uint8_t x, uint8_t y, uint32_t num, uint8_t len)
{
    uint8_t t,temp;
    uint8_t enshow=0;
    for(t=0; t<len; t++)
    {
        temp = (num / Oled_Pow(10, len - t - 1)) % 10;
        if(enshow == 0 && t < (len - 1))
        {
            if(temp == 0)
            {
                Oled_ShowChar(x+6*t,y,' ');
                continue;
            }else enshow=1;

        }
        Oled_ShowChar(x+6*t,y,temp+'0');
    }
}

uint32_t Oled_Pow(uint16_t a,uint16_t b)
{
    uint16_t c = 1;
    uint32_t res = a;
    if(b == 0) return 1;
    for(; c < b; c++) res *= res;
    return res;
}

void Oled_ShowNumber(uint8_t x,uint8_t y,int32_t num, uint8_t len)
{
    if(num>0)
        Oled_ShowNumberBase(x,y,num,len);
    else
    {
        Oled_ShowChar(x,y,'-');
        num=abs(num);
        Oled_ShowNumberBase(x+6,y,num,len-1);
    }
}

void Oled_ShowParam(uint8_t x, uint8_t y, const char* param_name, const int32_t param_value, uint8_t len)
{
   Oled_ShowString(x, y, param_name);
   Oled_ShowNumber(strlen(param_name)*6, y, param_value, len);
}
