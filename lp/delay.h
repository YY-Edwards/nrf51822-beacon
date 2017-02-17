//Copyright (c) 2014 LP电子
#ifndef __DELAY_H
#define	__DELAY_H

#include "nrf51.h"
#include <stdio.h>
#include "nrf_gpio.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include "led.h"

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

void delay_us(unsigned long ms);    //延时函数
void delay_ms(unsigned long ms);

#endif /* __DELAY_H */
