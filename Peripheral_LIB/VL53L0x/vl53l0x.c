/*
 * TOF.c
 *
 *  Created on: 2023/07/08
 *      Author: RATTAN
 */

#include "vl53l0x.h"

void Vl53l0x_Init()
{
    uint8_t VL53L0x_SendData[2] = {0x01};
    uint8_t VL53L0x_RecData[5] ;

    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_SYSRANGE_START, VL53L0x_SendData, 1);
    //HAL_Delay(500);

    VL53L0x_SendData[1] = 100;
    while(VL53L0x_SendData[1]--)
    {
        delay_ms(1);
        LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_RESULT_RANGE_STATUS, VL53L0x_RecData+4, 1);
            if (VL53L0x_RecData[4] & 0x01) break;
    }
}

uint8_t Vl53l0x_Check()
{
    uint8_t VL53L0x_SendData[2] = {0x01};
    uint8_t VL53L0x_RecData[5] ;

    //Revision ID:
    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_IDENTIFICATION_REVISION_ID, VL53L0x_RecData, 1);
    //Device ID:
    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_IDENTIFICATION_MODEL_ID, VL53L0x_RecData+1, 1);
    //PRE_RANGE_CONFIG_VCSEL_PERIOD =
    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD, VL53L0x_RecData+2, 1);
    //FINAL_RANGE_CONFIG_VCSEL_PERIOD=
    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD, VL53L0x_RecData+3, 1);

    LIB_I2C_Transmit(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_SYSRANGE_START, VL53L0x_SendData, 1);
    delay_ms(500);

    VL53L0x_SendData[1] = 100;
    while(VL53L0x_SendData[1]--)
    {
        delay_ms(10);
        LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_RESULT_RANGE_STATUS, VL53L0x_RecData+4, 1);
        if(VL53L0x_RecData[4] & 0x01) break;
    }

    if (VL53L0x_RecData[4] & 0x01)
    return 0;               //检查成功返回0
    else return 1;  //检查失败返回1
}

uint16_t Vl53l0x_MakeUint16(uint8_t Lbyte, uint8_t Hbyte)
{
    return (((uint16_t)Hbyte & 0xFF) << 8) | ((uint16_t)Lbyte & 0xFF);
}

void Vl53l0x_ConvOnce()
{
    LIB_I2C_Put(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_SYSRANGE_START, 0x01);
}

uint16_t Vl53l0x_GetDistance()
{
    uint8_t msg[12] = {0};
    LIB_I2C_Recive(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_RESULT_RANGE_STATUS, msg, 12);
    return Vl53l0x_MakeUint16(msg[11], msg[10]);

}
