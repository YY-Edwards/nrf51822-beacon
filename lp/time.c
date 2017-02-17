

//#include "nrf51.h"
#include "nrf_gpio.h"
#include "led.h"
#include "time.h"
#include <stdbool.h>
#include <stdint.h>

extern volatile  uint32_t tc_tick;
 
void time1_init(void)  //定时器初始化,定时1s
{

    NRF_TIMER2->MODE        = TIMER_MODE_MODE_Timer;
    NRF_TIMER2->PRESCALER   = 9;  //Ftimer  = 31250 Hz   =32us
 
    //NRF_TIMER2->CC[2]       = (31250U);  //=32us*31250=1s
	  NRF_TIMER2->CC[2]       = (1562U);  //=32us*1562=50ms
    NRF_TIMER2->INTENSET    = TIMER_INTENSET_COMPARE2_Enabled << TIMER_INTENSET_COMPARE2_Pos;

 
    NRF_TIMER2->SHORTS      = (TIMER_SHORTS_COMPARE1_CLEAR_Enabled << TIMER_SHORTS_COMPARE1_CLEAR_Pos);
		
		NVIC_ClearPendingIRQ(TIMER2_IRQn);
    NVIC_SetPriority(TIMER2_IRQn,3);
		NVIC_EnableIRQ(TIMER2_IRQn);  
	  NRF_TIMER2->TASKS_START = 1; //开启定时器
}


void TIMER2_IRQHandler(void)  //定时器中断模式服务函数
{
	
		tc_tick++;//中断一次计数1秒
	
    if ((NRF_TIMER2->EVENTS_COMPARE[2] == 1) && (NRF_TIMER2->INTENSET & TIMER_INTENSET_COMPARE2_Msk))
    {
      NRF_TIMER2->EVENTS_COMPARE[2] = 0;
   
      LED1_Toggle();//电平翻转void LED2_Toggle(void)


		 	NRF_TIMER2->TASKS_CLEAR = 1; //清楚计算
    }
 
}
