/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved.
 + 文件名  ：data_transfer.h
 + 描述    ：数据传输头文件
代码尽量做到逐行注释 代码有问题，及时加群交流 作者有偿支持对开源代码的完善 */
#ifndef _DATA_TRANSFER_H
#define	_DATA_TRANSFER_H

#include "stm32f4xx.h"
#include "height_ctrl.h"

/* 等待发送数据的标志 */
extern u8 wait_for_translate;
/* 等待发送数据的标志结构体 */
typedef struct
{
    u8 send_status;
    u8 send_speed;
    u8 send_rcdata;
    u8 send_motopwm;
    u8 send_senser;
    u8 send_senser2;
    u8 send_location;
    u8 send_power;
    u8 send_pid1;
    u8 send_pid2;
    u8 send_pid3;
    u8 send_pid4;
    u8 send_user;
} dt_flag_t;

/*----------------------------------------------------------
 + 实现功能：由任务调度调用周期1ms
----------------------------------------------------------*/
extern void Call_Data_transfer(void);

/*----------------------------------------------------------
 + 实现功能：数传初始化
----------------------------------------------------------*/
extern void Data_transfer_init(void);

/*----------------------------------------------------------
 + 实现功能：数据接收并保存
 + 调用参数：接收到的单字节数据
----------------------------------------------------------*/
extern void DT_Data_Receive_Prepare(u8 data);

void DT_Send_User(void);
void DT_Send_PID(u8 group,float p1_p,float p1_i,float p1_d,float p2_p,float p2_i,float p2_d,float p3_p,float p3_i,float p3_d);
void DT_Send_MotoPWM(u16 m_1,u16 m_2,u16 m_3,u16 m_4,u16 m_5,u16 m_6,u16 m_7,u16 m_8);
void DT_Send_Power(u16 votage, u16 current);
void DT_Send_RCData(u16 thr,u16 yaw,u16 rol,u16 pit,u16 aux1,u16 aux2,u16 aux3,u16 aux4,u16 aux5,u16 aux6);
void DT_Send_Senser2(s32 bar_alt,u16 csb_alt);
void DT_Send_Senser(s16 a_x,s16 a_y,s16 a_z,s16 g_x,s16 g_y,s16 g_z,s16 m_x,s16 m_y,s16 m_z);
void DT_Send_Status(float angle_rol, float angle_pit, float angle_yaw, s32 alt, u8 fly_model, u8 armed);
void DT_Send_Location(u8 state,u8 sat_num,s32 lon,s32 lat,s16 mode);
void DT_Send_Speed(float x_s,float y_s,float z_s);
void DT_Data_Receive_Prepare(u8 data);
void DT_Data_Receive_Anl(u8 *data_buf,u8 num);
static void DT_Send_Check(u8 head, u8 check_sum);
void DT_Send_Data(u8 *dataToSend , u8 length);

#endif
/* ©2015-2016 Beijing Bechade Opto-Electronic, Co.,Ltd. All rights reserved. */
