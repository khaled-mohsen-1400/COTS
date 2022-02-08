/************************************************/
/* Title       : main file                      */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 16, 2021                   */
/************************************************/


#define F_CPU 8000000UL

#include <avr/delay.h>

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_int.h"
#include "LCD_int.h"

#define F_CPU 8000000UL

		int main()

		{
			// Initialization
            DIO_vid_Init();
			LCD_vidInit();

			//variables declaration
			u8 Local_u8_counter1;
			u8 Local_u8_counter2;

			while(1)
			{
                for(Local_u8_counter1 = 0 , Local_u8_counter2 = 10; Local_u8_counter1 < 10 , Local_u8_counter2 > 0; Local_u8_counter1++ , Local_u8_counter2--)
                {
                	LCD_vidGoToRowCol(LINE1 , Local_u8_counter1);
                	LCD_vidWriteString("Khaled");
                	_delay_ms(110);

                	LCD_vidGoToRowCol(LINE2 , Local_u8_counter2);
                	LCD_vidWriteString("Mohsen");
                	_delay_ms(100);

                	LCD_vidClearScreen();
                	_delay_ms(100);

                } //end for number one



                for(Local_u8_counter1 = 10 , Local_u8_counter2 = 0; Local_u8_counter1 > 0 , Local_u8_counter2 < 10; Local_u8_counter1-- , Local_u8_counter2++)
                {
                	LCD_vidGoToRowCol(LINE1 , Local_u8_counter1);
                	LCD_vidWriteString("Khaled");
                	_delay_ms(110);

                	LCD_vidGoToRowCol(LINE2 , Local_u8_counter2);
                	LCD_vidWriteString("Mohsen");
                	_delay_ms(100);

                	LCD_vidClearScreen();
                	_delay_ms(100);

                } //end for number two


		     } //end while


	return 0;
	} // end main

