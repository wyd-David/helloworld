/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：driver_mpu6050.h
 + 描述    ：IMU传感器mpu6050驱动头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef _DRIVER_MPU6050_H
#define _DRIVER_MPU6050_H

#include "stm32f4xx.h"


/* 校准时的计算次数 */
#define OFFSET_AV_NUM 	    50
/* 滑动窗口滤波数值个数 */
#define FILTER_NUM 			10
/* Gyro角速度的单位转换 */
#define TO_ANGLE 			0.06103f

/* MPU6050结构体 */
//extern MPU6050_STRUCT mpu6050;


extern void MPU6050_Data_Offset(void);

/*----------------------------------------------------------
 + 实现功能：由任务调度调用周期2ms
----------------------------------------------------------*/
extern void Call_MPU6050_Data_Prepare(float T);



#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
