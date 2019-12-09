#include <stddef.h>
#include "torque.h"
#include "ctrl.h"
#include "database.h"
#include "SCS0009.h"
// u8 nDat[6] = {0X00, 0X00, 0X00, 0X14, 0X00, 0X64};

   
		
									

  u8 baund[2] = {0X04};
  u8 temp4=0X08,temp2=0X05,temp1=0X66,temp3=0X00;
	int p,p1;
	int t,q,t_last;
	
	

	void torque(int t_last)
	{
//	  Host2SCS(&temp1, &temp2, 4*(t_last+500));//+500
//		 Host2SCS(&temp3, &temp4, 4*(t_last+500));
//		WriteSCS(0x08, 0X2A,temp2,temp1,0X00, 0X00,0X02,0X64, 0x03);
//    WriteSCS(0x06, 0X2A,temp4,temp3,0X00, 0X00,0X02,0X64, 0x03);
		  Host2SCS(&temp1, &temp2, 4*(t_last+500));//+500
		 Host2SCS(&temp3, &temp4, 4*(t_last+500));
		WriteSCS(0x06, 0X2A,temp2,0X01,temp1, 0X00,0XE8,0X03,0xB7);
    WriteSCS(0x08, 0X2A,temp4,0X01,temp3, 0X00,0XE8,0X03,0xB7);
	}


//执行写指令

void writeBuf(u8 ID, u8 MemAddr, u8 *nDat, u8 nLen, u8 Fun)
{
    u8 i;
    u8 msgLen = 2;
    u8 bBuf[6];
    u8 CheckSum = 0;
    bBuf[0] = 0xff;
    bBuf[1] = 0xff;
    bBuf[2] = ID;
    bBuf[4] = Fun;
    if(nDat) {
        msgLen += nLen + 1;
        bBuf[3] = msgLen;
        bBuf[5] = MemAddr;
        Uart5_Send(bBuf, 6);

    } else {
        bBuf[3] = msgLen;
        Uart5_Send(bBuf, 5);
    }
    CheckSum = ID + msgLen + Fun + MemAddr;
    if(nDat) {
        for(i=0; i<nLen; i++) {
            CheckSum += nDat[i];
        }
        Uart5_Send(nDat, nLen);
    }
        CheckSum = ~CheckSum;
        Uart5_Send(&CheckSum, 1);
}


//写入ID，内存地址，位置，速度，指令
void WriteSCS(u8 ID, u8 MemAddr, u8 PositionH, u8 PositionL, u8 TimeH, u8 TimeL, u8 SpeedH, u8 SpeedL, u8 Fun){
	u8 buffer[6];
  buffer[0]= PositionH;
  buffer[1]=PositionL;
  buffer[2]=TimeH;
  buffer[3]=TimeL;
  buffer[4]=SpeedH;
  buffer[5]=SpeedL;
	writeBuf(ID, MemAddr, buffer, 6, Fun);
}
static u8	End = 1;//处理器大小端结构

void Host2SCS(u8 *DataL, u8* DataH, int Data)
{
	if(End){
		*DataL = (Data>>8);
		*DataH = (Data&0xff);
	}else{
		*DataH = (Data>>8);
		*DataL = (Data&0xff);
	}
}

//void snycWrite(u8 ID[], u8 IDN, u8 MemAddr, u8 *nDat, u8 nLen)
//{
//    u8 i,j;
//		u8 mesLen = ((nLen+1)*IDN+4);
//		u8 checkSum =0;
//		u8 bBuf[7];
//		bBuf[0]= 0xff;
//		bBuf[1]= 0xff;
//		bBuf[2]= 0xfe;
//		bBuf[3]= mesLen;
//		bBuf[4]= INST_SYNC_WRITE;
//		bBuf[5]= MemAddr;
//		bBuf[6]= nLen;
//		writeSCS(bBuf,7);
//	
//	checkSum= 0xfe+ mesLen + INST_SYNC_WRITE + MemAddr + nLen;
//	for(i=0; i<IDN; i++)
//	{
//		writeSCS(ID+i,i);
//		checkSum += ID[i];
//		for(j=0; j<nLen; j++){
//			checkSum += nDat[j];
//	}
//}
//	checkSum += ~checkSum;
//	writeSCS(&checkSum,1);
//}

/*
void ScsWritePosition(u8 ID,int16_t Position,u16 Time,u16 Speed)
{
u8 buffer[20];
u8 ctemp;
u8 temp=0;
u8 BuffIndex=0;
buffer[BuffIndex++] = 0xff;
buffer[BuffIndex++] = 0xff;
buffer[BuffIndex++] = ID;
buffer[BuffIndex++] = 0x09;//指令包数据长度
buffer[BuffIndex++] = 0x03; // 指令
buffer[BuffIndex++] = 0x2a;	// 首地址
	
temp+=ID;
temp+= 0x09;
temp+= 0x03;
temp+= 0x2a;
//			*DataL = (Data>>8);
//		*DataH = (Data&0xff);
//位置  
	if(Position<0)Position=32768-Position;
ctemp =(Position&0xff) ;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	
ctemp=(Position>>8);
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Time;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Time>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Speed;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Speed>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	


// if(temp) 
//			buffer[BuffIndex++] = temp; 
// else{
//		  temp = ~temp;		
//      buffer[BuffIndex++] = temp; 
//		}
		  temp = ~temp;		
      buffer[BuffIndex++] = temp;  
	
 Uart5_Send(buffer,BuffIndex);
}

void ScsSyncWritePosition(u8 ID1,int16_t Position1,u16 Time1,u16 Speed1,
	                        u8 ID2,int16_t Position2,u16 Time2,u16 Speed2)
{
u8 buffer[20];
u8 ctemp;
u8 temp=0;
u8 BuffIndex=0;
buffer[BuffIndex++] = 0xff;
buffer[BuffIndex++] = 0xff;
buffer[BuffIndex++] = 0xFE;  //ID
buffer[BuffIndex++] = 0x12;//指令包数据长度 (每个舵机数据长度+1)*舵机个数+4
buffer[BuffIndex++] = 0x83; // 指令
	buffer[BuffIndex++] = 0x2a; 
	buffer[BuffIndex++] = 0x06; 

	
temp+= 0xfe;
temp+= 0x12;
temp+= 0x83;
temp+= 0x2a;
temp+= 0x06;
//==========第一个舵机参数===============	
buffer[BuffIndex++] = ID1;	// 首地址
ctemp = ID1;
temp+=ctemp;	
//位置  
	if(Position1<0)Position1=32768-Position1;
ctemp =(Position1&0xff) ;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	
ctemp=(Position1>>8);
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Time1;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Time1>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Speed1;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Speed1>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	
//==========第二个舵机参数===============
buffer[BuffIndex++] = ID2;	// 首地址
ctemp = ID2;
temp+=ctemp;	
//位置  
	if(Position2<0)Position2=32768-Position2;
ctemp =(Position2&0xff) ;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	
ctemp=(Position2>>8);
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Time2;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Time2>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

ctemp = Speed2;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);
ctemp=Speed2>>8;
temp+=ctemp;
buffer[BuffIndex++] = (ctemp);	

		  temp = ~temp;		
      buffer[BuffIndex++] = temp;  
	
 Uart5_Send(buffer,BuffIndex);
}*/
