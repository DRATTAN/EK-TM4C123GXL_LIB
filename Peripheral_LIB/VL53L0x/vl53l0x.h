/*
 * tof.h
 *
 *  Created on: 2023/07/08
 *      Author: RATTAN
 */

#ifndef PERIPHERAL_LIB_TOF_VL53L0X_H_
#define PERIPHERAL_LIB_TOF_VL53L0X_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_i2c.h"
#include "time.h"

#define Vl53l0x_Addr 0x52 >> 1
#define I2C_Num I2C0


#define VL53L0X_REG_IDENTIFICATION_MODEL_ID         0xc0
#define VL53L0X_REG_IDENTIFICATION_REVISION_ID      0xc2
#define VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD   0x50
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD 0x70
#define VL53L0X_REG_SYSRANGE_START                  0x00
#define VL53L0X_REG_RESULT_INTERRUPT_STATUS         0x13
#define VL53L0X_REG_RESULT_RANGE_STATUS             0x14

void Vl53l0x_Init(void);
uint8_t Vl53l0x_Check(void);
uint16_t Vl53l0x_MakeUint16(uint8_t, uint8_t);
void Vl53l0x_ConvOnce(void);
uint16_t Vl53l0x_GetDistance(void);
#endif /* PERIPHERAL_LIB_TOF_VL53L0X_H_ */
