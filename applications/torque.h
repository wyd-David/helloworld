#ifndef __USRAT3_H
#define __USRAT3_H 
#include "stm32f4xx.h"

extern u8 Usart3_Receive;
extern int t,t_last;
void uart2_init(u32 pclk2,u32 bound);
void USART2_IRQHandler(void);
int writeSCS(unsigned char *nDat, int nLen);
extern void torque(int t_last);
//extern void torqueinit();
extern u8 position[256];
void Host2SCS(u8 *DataL, u8* DataH, int Data);

void writeBuf(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen, u8 Fun);
void WriteSCS(u8 ID, u8 MemAddr, u8 PositionH, u8 PositionL, u8 TimeH, u8 TimeL, u8 SpeedH, u8 SpeedL, u8 Fun);
#endif

