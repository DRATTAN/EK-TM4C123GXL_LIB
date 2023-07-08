/*
 * lib_i2c.c
 *
 *  Created on: 2023/05/27
 *      Author: RATTAN
 */


#include "lib_i2c.h"


void LIB_I2C_Init(uint8_t I2CNum, uint8_t SpeedMod)
{
    uint32_t I2C_INIT_TABLE[4][5] = {{GPIO_PB2_I2C0SCL, GPIO_PB3_I2C0SDA, GPIO_PORTB_BASE, GPIO_PIN_2, SYSCTL_PERIPH_GPIOB},
                                     {GPIO_PA6_I2C1SCL, GPIO_PA7_I2C1SDA, GPIO_PORTA_BASE, GPIO_PIN_6, SYSCTL_PERIPH_GPIOA},
                                     {GPIO_PE4_I2C2SCL, GPIO_PE5_I2C2SDA, GPIO_PORTE_BASE, GPIO_PIN_4, SYSCTL_PERIPH_GPIOE},
                                     {GPIO_PD0_I2C3SCL, GPIO_PD1_I2C3SDA, GPIO_PORTD_BASE, GPIO_PIN_0, SYSCTL_PERIPH_GPIOD}};
    if(I2CNum < 4)
    {
        SysCtlPeripheralEnable(I2C_INIT_TABLE[I2CNum][4]);
        SysCtlPeripheralEnable (SYSCTL_PERIPH_I2C0 + I2CNum);
        SysCtlPeripheralReset (SYSCTL_PERIPH_I2C0 + I2CNum);
        GPIOPinConfigure (I2C_INIT_TABLE[I2CNum][0]);
        GPIOPinConfigure (I2C_INIT_TABLE[I2CNum][1]);
        GPIOPinTypeI2CSCL (I2C_INIT_TABLE[I2CNum][2], I2C_INIT_TABLE[I2CNum][3]);
        GPIOPinTypeI2C (I2C_INIT_TABLE[I2CNum][2], I2C_INIT_TABLE[I2CNum][3] << 1);
        I2CMasterInitExpClk (I2C0_BASE + (I2CNum << 12), SysCtlClockGet(), SpeedMod);
        HWREG((I2C0_BASE + (I2CNum << 12)) + I2C_O_FIFOCTL) = 80008000;
    }
}

void LIB_I2C_Send(uint8_t I2CNum, uint16_t Dev_Addr, uint16_t Reg_Addr, uint8_t Data)
{

    I2CMasterSlaveAddrSet(I2C0_BASE + (I2CNum << 12), Dev_Addr, false);
    I2CMasterDataPut(I2C0_BASE + (I2CNum << 12), Reg_Addr);
    I2CMasterControl(I2C0_BASE + (I2CNum << 12), I2C_MASTER_CMD_BURST_SEND_START);
    while(I2CMasterBusy(I2C0_BASE + (I2CNum << 12))) ;
    I2CMasterDataPut(I2C0_BASE + (I2CNum << 12), Data);
    I2CMasterControl(I2C0_BASE + (I2CNum << 12), I2C_MASTER_CMD_BURST_SEND_FINISH);
    while(I2CMasterBusy(I2C0_BASE + (I2CNum << 12))) ;
}

void LIB_I2C_Transmit(uint8_t I2CNum, uint16_t Dev_Addr, uint16_t Reg_Addr, uint8_t* Dpoint, uint32_t counter)
{
    uint32_t count = 0;
    I2CMasterSlaveAddrSet(I2C0_BASE + (I2CNum << 12), Dev_Addr, false);
    I2CMasterDataPut(I2C0_BASE + (I2CNum << 12), Reg_Addr);
    I2CMasterControl(I2C0_BASE + (I2CNum << 12), I2C_MASTER_CMD_BURST_SEND_START);
    while(I2CMasterBusy(I2C0_BASE + (I2CNum << 12))) ;
    for(;count < counter - 1; count++)
    {
        I2CMasterDataPut(I2C0_BASE + (I2CNum << 12), *(Dpoint + count));
        I2CMasterControl(I2C0_BASE + (I2CNum << 12), I2C_MASTER_CMD_BURST_SEND_CONT);
        while(I2CMasterBusy(I2C0_BASE + (I2CNum << 12))) ;
    }
    I2CMasterDataPut(I2C0_BASE + (I2CNum << 12), *(Dpoint + counter-1));
    I2CMasterControl(I2C0_BASE + (I2CNum << 12), I2C_MASTER_CMD_BURST_SEND_FINISH);
    while(I2CMasterBusy(I2C0_BASE + (I2CNum << 12))) ;
}
