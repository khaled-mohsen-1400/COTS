/*
 * HLCD_prog.c
 *
 *  Created on: Aug 24, 2021
 *      Author: mosta
 */
#include "stdtypes.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "util/delay.h"
#include "LCD_config.h"

void LCD_void_WriteCMD(u8 ARG_u8_CMD)
{
	DIO_void_SETPIN(LCD_RS_PIN,DIO_LOW);
	_delay_ms(1);
	DIO_void_SETPORT_VALUE(LCD_DATA_PORT,ARG_u8_CMD);
	DIO_void_SETPIN(LCD_EN_PIN,DIO_LOW);
	DIO_void_SETPIN(LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_void_SETPIN(LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);

}
void LCD_void_INTIALIZE(void)
{
	_delay_ms(35);
	LCD_void_WriteCMD(0x38);
	_delay_ms(1);
	LCD_void_WriteCMD(0x07);
	_delay_ms(1);
	LCD_void_WriteCMD(0x01);
	_delay_ms(2);
	LCD_void_WriteCMD(0x06);
	_delay_ms(1);

}
void LCD_void_WriteDATA(u8 ARG_u8_DATA)
{
	DIO_void_SETPIN(LCD_RS_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_void_SETPIN(LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	DIO_void_SETPORT_VALUE(LCD_DATA_PORT,ARG_u8_DATA);
	_delay_ms(1);
	DIO_void_SETPIN(LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);
}
//void LCD_void_CLRDISPLAY(void);
