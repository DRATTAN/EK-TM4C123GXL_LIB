/*
 * TOF.c
 *
 *  Created on: 2023/07/08
 *      Author: RATTAN
 */

#include <vl53l0x.h>

void Vl53l0x_Init()
{
    uint8_t VL53L0x_SendData[2] = {0x01, 100};
    uint8_t VL53L0x_RecData[5] ;
    LIB_I2C_Send(I2C_Num, Vl53l0x_Addr, VL53L0X_REG_SYSRANGE_START, VL53L0x_SendData[0]);
    while(VL53L0x_SendData[1]--)
    {
        delay_ms(1);
        HAL_I2C_Mem_Read(I2c_Addr, VL53L0x_add, VL53L0X_REG_RESULT_RANGE_STATUS, I2C_MEMADD_SIZE_8BIT, VL53L0x_RecData+4, 1, 1);
        if (VL53L0x_RecData[4] & 0x01) break;
    }
}
