#include "sys.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include "beep.h"
#include "us_100.h"

//串口触发方式
//
//输入捕获实验更改得到，
//Trig 接  PA(1)
//Echo 接  PA(0)----TIM5-Ch1
// VCC 2.4-5.5V
// GND

int main(void)
{	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);
	uart_init(115200);//初始化串口波特率为115200
	led_init();
	key_init();
	beep_init();
	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); //以1Mhz的频率计数 timer5是32位的。
	LED0 = 0;
	
	while(1)
	{	
		delay_ms(100);
		distance();

	}

}
