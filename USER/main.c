#include "sys.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"
#include "beep.h"
#include "us_100.h"

//���ڴ�����ʽ
//
//���벶��ʵ����ĵõ���
//Trig ��  PA(1)
//Echo ��  PA(0)----TIM5-Ch1
// VCC 2.4-5.5V
// GND

int main(void)
{	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
	led_init();
	key_init();
	beep_init();
	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); //��1Mhz��Ƶ�ʼ��� timer5��32λ�ġ�
	LED0 = 0;
	
	while(1)
	{	
		delay_ms(100);
		distance();

	}

}
