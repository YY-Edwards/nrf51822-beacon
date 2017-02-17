
#include "delay.h"
void delay_ms(unsigned long ms)    //延时函数
{                         
	unsigned long a;
	while(ms)
	{
		a=2585;      
		while(a--);
		ms--;
	}
}

void delay_us(unsigned long ms)    //延时函数4us
{                         
	unsigned long a;
	while(ms)
	{
		a=1;
		while(a--);
		ms--;
	}
}

