/*
 * APP.c
 *
 * Created: 3/27/2023 5:34:42 PM
 *  Author: youssef's
 */ 

//includes
#include "../includes/APP.h"



/************************************************************************/
/*								APIs                                    */
/************************************************************************/
uint8 data = 0;
uint8 string_data[16];
uint8 counter = 0;
void INIT(void){
	SPI_INIT();
	LCD_INIT();
}
void APP(void){
	data = SPI_SEND_RECIEVE(0);
	if(data == '*' ){
		LCD_clear_screen();
		LCD_WRITE_STRING(string_data);
		for(uint8 i=0;i<counter;i++){
			string_data[i] = '\0';
		}
		counter =0;
		}else{
		string_data[counter] = data;
		counter++;
	}
}