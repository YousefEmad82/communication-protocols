/*
 * APP.c
 *
 * Created: 3/27/2023 5:52:50 PM
 *  Author: youssef's
 */ 
//includes
#include "../includes/APP.h"


/************************************************************************/
/*									APIs                                */
/************************************************************************/
volatile uint8 string_data[16];
volatile uint8 counter = 0;
uint8 data;

void BUTTON1_INT(){ //when pressed the last character is removed from the string
	counter--;
}

void BUTTON2_INT(){ //when pressed the spi sends the string
	
	for(uint8 i=0;i<counter;i++){
		SPI_SEND_RECIEVE(string_data[i]);
	}
	SPI_SEND_RECIEVE('*');
	counter = 0;
}

void INIT(void){
	SREG |=(1<<7);//enable global interrupt of avr 
	external_interrupt_register_callback(BUTTON1_INT,INT_1);
	external_interrupt_register_callback(BUTTON2_INT,INT_0);
	UART_INIT();
	SPI_INIT();
	EXT_INT_Init();
	EXT_INT_SET_CONFIG();
	LCD_INIT();
	
}
void APP(void){
	data = UART_RECIEVE();
	string_data[counter] = data;
	counter++;
}