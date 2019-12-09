/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：device_ak8975.h
 + 描述    ：磁力计（电子罗盘）设备头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef _DEVICE_AK8975_H_
#define	_DEVICE_AK8975_H_

#include "stm32f4xx.h"


/*----------------------------------------------------------
 + 实现功能：磁力计采样触发
 + 返回参数：磁力计运行标识
----------------------------------------------------------*/
extern uint8_t AK8975_IS_RUN(void);

/*----------------------------------------------------------
 + 实现功能：获取磁力计X方向数据
 + 返回参数：磁力计X轴原始数据
----------------------------------------------------------*/
extern int16_t AK8975_Read_Mag_X(void);

/*----------------------------------------------------------
 + 实现功能：获取磁力计Y方向数据
 + 返回参数：磁力计Y轴原始数据
----------------------------------------------------------*/
extern int16_t AK8975_Read_Mag_Y(void);

/*----------------------------------------------------------
 + 实现功能：获取磁力计Z方向数据
 + 返回参数：磁力计Z轴原始数据
----------------------------------------------------------*/
extern int16_t AK8975_Read_Mag_Z(void);

#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
