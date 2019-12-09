#ifndef __SCS2332_H
#define __SCS2332_H
#include "stm32f4xx.h"
extern u8 Usart3_Receive;
extern int t_last;
extern int t;
int writeSCS(unsigned char *nDat, int nLen);
void torque(int t_last);
//extern void torqueinit();
extern u8 position[256];
void Host2SCS(u8 *DataL, u8* DataH, int Data);

void writeBuf(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen, u8 Fun);
void WriteSCS(u8 ID, u8 MemAddr, u8 PositionH, u8 PositionL, u8 TimeH, u8 TimeL, u8 SpeedH, u8 SpeedL, u8 Fun);

void ScsWritePosition(u8 ID,int16_t Position,u16 Time,u16 Speed);
void ScsSyncWritePosition(u8 ID1,int16_t Position1,u16 Time1,u16 Speed1,
	                        u8 ID2,int16_t Position2,u16 Time2,u16 Speed2);


#endif


