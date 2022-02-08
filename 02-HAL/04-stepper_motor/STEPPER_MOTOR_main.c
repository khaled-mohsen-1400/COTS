/*

 * STEPPER_MOTOR_main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Khaled
 */

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <avr/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"
#include "STEPPER_MOTOR_INT.h"

void main()
{
	//initialization

	u8 Local_u8Index ;
	u8 Local_u8_Speed = 0;
	uint16 Local_uint16RetValue = 0 ;
	uint16 Local_uint16_Direc = 2;
	uint16 Local_uint16_Value;
    u8 Local_u8_Flag;

	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();
	Smotor_vid_int();

	LCD_vidClearScreen();
	LCD_vidGoToRowCol(0 , 7);
	LCD_vidWriteString("ST");
	LCD_vidGoToRowCol(1 , 7);
	LCD_vidWriteString("DC");

	while(1)
	{
		Local_uint16RetValue = KeyPad_uint16GetStatus();
		_delay_ms(150);

		for(Local_u8Index = 0 ; Local_u8Index < 16 ; Local_u8Index++)
		{
			if( GET_BIT(Local_uint16RetValue , Local_u8Index) )
			{


				    Local_uint16_Value = Keypad_u8_AdjustKey(Local_u8Index);

				    if(Local_uint16_Value == 'A')
				    {
				     LCD_vidGoToRowCol(0 , 0);
				     LCD_vidWriteString("  ");
				     LCD_vidWriteString("S1");
				     Local_u8_Speed = 14;

				    }
				    else if(Local_uint16_Value == 'B')
				    {
				     LCD_vidGoToRowCol(0 , 0);
				     LCD_vidWriteString("  ");
				     LCD_vidWriteString("S2");
				     Local_u8_Speed = 10;

				    }
				    else if(Local_uint16_Value == 'C')
				    {
				     LCD_vidGoToRowCol(0 , 0);
				     LCD_vidWriteString("  ");
				     LCD_vidWriteString("S3");
				     Local_u8_Speed = 6;

				    }
				    else if(Local_uint16_Value == 'D')
				    {
				     LCD_vidGoToRowCol(0 , 0);
				     LCD_vidWriteString("  ");
				     LCD_vidWriteString("S4");
				     Local_u8_Speed = 2;

				    }

				 else if(Local_uint16_Value == 'R')
				 {
				     LCD_vidGoToRowCol(0 , 11);
				     LCD_vidWriteString("   ");
				     LCD_vidWriteString("CW");
				     Local_uint16_Direc = 1;

				 }

				 else if(Local_uint16_Value == 'L')
				 {
				     LCD_vidGoToRowCol(0 , 11);
				     LCD_vidWriteString("   ");
				     LCD_vidWriteString("CCW");
					 Local_uint16_Direc = 0;

				 }


				 else if(Local_uint16_Value == 'S')
				 {
					 Smotor_vid_int();
				     LCD_vidGoToRowCol(0 , 11);
				     LCD_vidWriteString("   ");
				     LCD_vidWriteString("OFF");
				     LCD_vidGoToRowCol(0 , 0);
				     LCD_vidWriteString("  ");
				     LCD_vidWriteString("0");

				 }

				   			} //end if

		} //end for
		Smotor_vid_setSpeed_Direc(Local_u8_Speed , Local_uint16_Direc);

	} //end while

} //end main
