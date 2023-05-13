/*EK-TM4C123GXL_LIB
 * ����:RATTAN
 * �ļ�����:none
 */

#include "lib_clock.h"

/*
 * ����:����ϵͳʱ��Ƶ��
 * ����
 *  @DIV:
 *       CLOCK_XTAL_PLL_80M:����ϵͳʱ��Ϊ80HMz
 *       CLOCK_XTAL_PLL_40M:����ϵͳʱ��Ϊ40HMz
 *       CLOCK_XTAL_PLL_20M:����ϵͳʱ��Ϊ20HMz
 *       CLOCK_XTAL_PLL_10M:����ϵͳʱ��Ϊ10HMz
 *       CLOCK_XTAL_PLL_5M:����ϵͳʱ��Ϊ5HMz
 * ����ֵ:void
 * ��ע:����TM4C123GXL,ϵͳʱ�Ӳ��ɳ���80MHz
 */
void LIB_CLOCK_MainClockSet(uint32_t DIV)
{
    SysCtlClockSet(DIV| SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    return ;
}

/*
 * ����:ʹ������ʱ�Ӳ��ȴ����������
 * ����
 *  @PeripheralAddr:
 *       �������ַ,����:
 *       GPIO_PORTB_AHB_BASE
 *       GPIO_PORTB_BASE
 * ����ֵ:void
 * ��ע:��ʱ��δ��ʼ�����,���ֹ��������,������������.��1ms��ʱ��δ��ʼ�����,��������Ӳ��.
 */
void LIB_CLOCK_PeripheralClockEnable(uint32_t PeripheralAddr)
{
    SysCtlPeripheralEnable(PeripheralAddr);
    while(!SysCtlPeripheralReady(PeripheralAddr)) ;
    return;
}

/*
 * ����:�ر�����ʱ�Ӳ��ȴ����������
 * ����
 *  @PeripheralAddr:
 *       �������ַ,����:
 *       GPIO_PORTB_AHB_BASE
 *       GPIO_PORTB_BASE
 * ����ֵ:void
 * ��ע:��ʱ��ִ�йرպ�δ�ر����,���ֹ��������,������������.��1ms��ʱ��δ�ر����,��������Ӳ��.
 */
void LIB_CLOCK_PeripheralClockDisable(uint32_t ui32Peripheral)
{
    SysCtlPeripheralDisable(ui32Peripheral);
    while(SysCtlPeripheralReady(ui32Peripheral)) ;
    return;
}
