
#ifndef __LED_H
#define	__LED_H

//#include "nrf51.h"
#include "nrf6310.h"


 
//#define LED_0          19
//#define LED_1          20  

void led_init(void);
void LED1_Open(void);
void LED1_Close(void);
void LED1_Toggle(void);
void LED2_Open(void);
void LED2_Close(void);
void LED2_Toggle(void);
 
#endif /* __LED_H */
