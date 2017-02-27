#ifndef __UART_H
#define	__UART_H

#include "nrf51.h"
#include <stdio.h>

#define PRO_RX_PIN_NUMBER  11   // UART RX pin number.
#define PRO_TX_PIN_NUMBER  9    // UART TX pin number.
#define PRO_CTS_PIN_NUMBER 10    // UART Clear To Send pin number. Not used if HWFC is set to false
#define PRO_RTS_PIN_NUMBER 8    // Not used if HWFC is set to false
#define PRO_HWFC           false // UART hardware flow control


void USART_Configuration(void);
void uart_exit(void);
void UART0_IRQHandler(void);
int fputc(int ch, FILE *f);
void UART_send_byte(uint8_t byte);
void UART_Send(uint8_t *Buffer, uint32_t Length);
uint8_t UART_Recive(void);

void uart_data_handler(uint8_t *p_data, uint16_t length);

#endif /* __UART_H */
