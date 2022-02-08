/************************************************/
/* Title       : KeyPad main file               */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 17, 2021                   */
/************************************************/



#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

/*
#define F_CPU 8000000UL

#include "util/delay.h"
 */

#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"

void main()
{

	u8 Local_u8Index ;
	u16 Local_u16RetValue = 0 ;
	u8 Local_ones ;
	u8 Local_tens ;
	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();

	LCD_vidWriteString("HELLO WORLD");

	_delay_ms(2000);
	LCD_vidClearScreen();




	while(1)
	{
		Local_u16RetValue = KeyPad_u16GetStatus();
		_delay_ms(150);
		for(Local_u8Index = 0 ; Local_u8Index < 16 ; Local_u8Index++)
		{
			if( GET_BIT(Local_u16RetValue , Local_u8Index) )
			{
				if(Local_u8Index <= 9)
				{
					LCD_vidGoToRowCol(0 , 0);
					LCD_vidWriteCharacter(Local_u8Index+ '0');
					LCD_vidWriteCharacter(' ');
					_delay_ms(500);
				}
				else if(Local_u8Index >= 10 && Local_u8Index <= 15)
				{
					Local_ones = Local_u8Index % 10 ;
					Local_tens = Local_u8Index / 10 ;
					LCD_vidGoToRowCol(0 , 0);
					LCD_vidWriteCharacter(Local_tens + 48);
					LCD_vidWriteCharacter(Local_ones + '0' );
					_delay_ms(500);
				}
			}

		}


	}


}
