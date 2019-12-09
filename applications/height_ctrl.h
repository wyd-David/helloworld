/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：height_ctrl.h
 + 描述    ：高度控制头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef __HEIGHT_CTRL_H
#define __HEIGHT_CTRL_H

#include "stm32f4xx.h"



/* 气压计速度 滑动窗口滤波数组 数量 */
#define BARO_SPEED_NUM 100
/* 油门控制量转换高度控制 */
#define EXP_Z_SPEED  ( 4.0f *my_deathzoom((thr-500),50) )

/* 超声波定高标准比例高度速度控制 单位 mm/s */
#define ULTRA_SPEED 		 0.625f
/* 超声波定高最大高度上升速度控制 单位 mm/s */
#define Max_ULTRA_SPEED 		 250.0f
/* 超声波定高最大高度下降速度控制 单位 mm/s */
#define Min_ULTRA_SPEED 		 -150.0f

/* 超声波定高最大高度位置控制 单位 mm */
#define ULTRA_MAX_HEIGHT 1500
/* 超声波定高最小高度位置控制 单位 mm */
#define ULTRA_MIN_HEIGHT 200

/* 超声波定高积分限幅 单位 mm */
#define ULTRA_INT        300


/* 高度位置或速率PID控制量结构体 */
typedef struct
{
    float err;
    float err_old;
    float err_d;
    float err_i;
    float pid_out;

} _st_height_pid_v;

/* 高度位置或速率PID参数结构体 */
typedef struct
{
    float kp;
    float kd;
    float ki;

} _st_height_pid;

/* 气压计有接收到数据状态 */
extern u8 baro_ctrl_start;
/* 气压计高度 */
extern float baro_height;
/* 加速度在各方向的分量 */
extern float wz_acc,north_acc,west_acc;
/* 速度在各方向的分量 */
extern float wz_speed,north_speed,west_speed;
/* 定高高度速率PID输出量 */
extern float height_ctrl_out;

/* 最初启动气压定高 */
extern float start_height;
/*----------------------------------------------------------
 + 实现功能：油门控制高度
 + 调用参数：两次调用时间间隔，油门信号量
----------------------------------------------------------*/
extern void Height_Ctrl(float T,float thr);

/*----------------------------------------------------------
 + 实现功能：气压定高的PID参数初始化
----------------------------------------------------------*/
extern void WZ_Speed_PID_Init(void);

/*----------------------------------------------------------
 + 实现功能：高度的速度控制
 + 调用参数：两次调用时间间隔 遥控器油门控制量 期望垂直方向速度 垂直方向速度
----------------------------------------------------------*/
extern void height_speed_ctrl(float T,float thr,float exp_z_speed,float );

/*----------------------------------------------------------
 + 实现功能：气压计定高控制
 + 调用参数：两次调用时间间隔 遥控器油门控制量
----------------------------------------------------------*/
extern void Baro_Ctrl(float T,float thr);

/*----------------------------------------------------------
 + 实现功能：超声波定高的PID参数初始化
----------------------------------------------------------*/
extern void Ultra_PID_Init(void);

/*----------------------------------------------------------
 + 实现功能：超声波定高控制
 + 调用参数：两次调用时间间隔 遥控器油门控制量
----------------------------------------------------------*/
extern void Ultra_Ctrl(float T,float thr);





#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
