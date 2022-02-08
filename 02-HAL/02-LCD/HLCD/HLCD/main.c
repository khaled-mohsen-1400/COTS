/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: mosta
 */
#include "bitmath.h"
#include "stdtypes.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include <util/delay.h>

int main()
{
	DIO_void_SETPORT_DIR(DIO_PORT_A,0xff);
	DIO_void_SETPORT_DIR(DIO_PORT_C,0xff);
	LCD_void_INTIALIZE();

	while(1)
	{
		LCD_void_WriteDATA('A');
		_delay_ms(3);

	}

	return 0;
}
