/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：rc.h
 + 描述    ：遥控器通道数据处理头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef _RC_H
#define	_RC_H

#include "stm32f4xx.h"
extern s16 CH[8];
extern int t;
/*----------------------------------------------------------
 + 实现功能：由任务调度调用周期2ms
    接收机控制量数组：Mapped_CH 1000-1500-2000
    数传控制量数组：RX_CH     1000-1500-2000
    无控制量数组：STOP_CH   1000-1500-2000
----------------------------------------------------------*/
extern void Call_RadioContrl(float inner_loop_time);

/*----------------------------------------------------------
 + 实现功能：遥控信号虚拟看门狗，400ms内必须调用一次
 + 调用参数：控制信号类型：1为PWM信号 2为数传
----------------------------------------------------------*/
extern void Call_RadioControl_Sign(u8 ch_mode);

/*----------------------------------------------------------
 + 实现功能：控制模式判断 由任务调度调用周期50ms
----------------------------------------------------------*/
extern void Call_RadioControl_Mode(void);

#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
