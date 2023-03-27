/*
 * APP.h
 *
 * Created: 3/27/2023 5:34:32 PM
 *  Author: youssef's
 */ 


#ifndef APP_H_
#define APP_H_
//includes
#include "../../HAL/includes/LCD.h"
#include "stdio.h"
#include "../../MCAL/includes/UART_Interface.h"
#include "../../MCAL/includes/SPI_interface.h"
#include "../../MCAL/includes/DIO_Interface.h"
#include "../../MCAL/includes/External_INT_Interface.h"


/************************************************************************/
/*								APIs                                    */
/************************************************************************/

void INIT(void);
void APP(void);



#endif /* APP_H_ */