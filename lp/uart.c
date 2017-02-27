#include "nrf51.h"
#include "nrf_gpio.h"
#include "uart.h"
#include "simple_uart.h"
#include "pro_slip.h"
#include <stdarg.h>
#include <stdio.h>



void USART_Configuration(void)//���ڳ�ʼ������
  {  

    simple_uart_config(PRO_RTS_PIN_NUMBER, PRO_TX_PIN_NUMBER, PRO_CTS_PIN_NUMBER, PRO_RX_PIN_NUMBER, PRO_HWFC);
 //   nrf_gpio_cfg_output(ERROR_PIN); // ERROR_PIN configured as output.

		}		
	

void uart_data_handler(uint8_t *p_data, uint16_t length)
{
	 data_packet_send((char *)p_data, length);
	//printf("\r\n*****beacon data send okay!*****\r\n");
}


		

void uart_exit(void)
{
 
    NRF_UART0->INTENSET = UART_INTENSET_RXDRDY_Enabled << UART_INTENSET_RXDRDY_Pos;
    
    NVIC_SetPriority(UART0_IRQn, 1);
    NVIC_EnableIRQ(UART0_IRQn);

}
		
void UART0_IRQHandler(void)
{
    static uint8_t data_array;

    data_array = simple_uart_get();

       simple_uart_put(data_array);


}
		
		
		
/************************************************************** 
* ������  : fputc()
* ����    : �ض���putc��������������ʹ��printf�����Ӵ���1��ӡ���
* ����    : None
* ���    : None
* ����    : None
* ����    : ���
* ��������: 2014.1.1
* �汾    : V1.00
*************************************************************/
//int fputc(int ch, FILE *f)
//{
//		/* Place your implementation of fputc here */
//		/* ����һ���ֽڵ����� */
//		simple_uart_put((uint8_t)ch);
//		/* �ȴ�������� */
//		return ch;
//}

/************************************************************** 
* ������  : fputc()
* ����    : �ض���putc��������������ʹ��printf�����Ӵ���1��ȡ����
* ����    : None
* ���    : None
* ����    : None
* ����    : ���
* ��������: 2014.1.1
* �汾    : V1.00
*************************************************************/
int fgetc(FILE *f)
{
		/* �ȴ�����1�������� */
		/* ���ؽ��յ������� */
		return (int)simple_uart_get();
}
