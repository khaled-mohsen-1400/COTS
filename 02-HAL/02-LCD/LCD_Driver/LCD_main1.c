/************************************************/
/* Title       : LCD main2 file                 */
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
			uint8 Local_uint8_counter1;
			uint8 Local_uint8_counter2;



			while(1)
			{



				for(Local_uint8_counter1 = 0 , Local_uint8_counter2 = 5 ; Local_uint8_counter1 <= 5  && Local_uint8_counter2 >= 0; Local_uint8_counter1++ , Local_uint8_counter2--)
                {

                LCD_vidClearScreen();
                _delay_ms(100);
        	    LCD_vidGoToRowCol(LINE2 , Local_uint8_counter2+10);
        	    LCD_vidWriteString("Mohsen"); //generate
        	    _delay_ms(50);

                LCD_vidGoToRowCol(LINE1 , Local_uint8_counter1+11);
        	    LCD_vidWriteString("Khaled"); //remove
        	    _delay_ms(50);

                if(Local_uint8_counter1 != 5)
                {
        	    LCD_vidGoToRowCol(LINE2 , 0); //remove
        	    LCD_vidWriteString_By_INDX("ohsen" , Local_uint8_counter1);
        	    _delay_ms(50);
                }

        	    LCD_vidGoToRowCol(LINE1 , 0); //generate
        	    LCD_vidWriteString_By_INDX("Khaled" , Local_uint8_counter2);
        	    _delay_ms(50);




                } //end for



				for(Local_uint8_counter1 = 9 , Local_uint8_counter2 = 1; Local_uint8_counter1 >= 1 || Local_uint8_counter2 <= 9 ;Local_uint8_counter1-- , Local_uint8_counter2++)
                {


					LCD_vidClearScreen();
					_delay_ms(100);
                	LCD_vidGoToRowCol(LINE2 , Local_uint8_counter1);
                	LCD_vidWriteString("Mohsen");
                	_delay_ms(100);

                	LCD_vidGoToRowCol(LINE1 , Local_uint8_counter2);
                	LCD_vidWriteString("Khaled");
                	_delay_ms(100);

					}//end for

				    LCD_vidClearScreen();
            	    LCD_vidGoToRowCol(LINE1 , Local_uint8_counter2);
            	    LCD_vidWriteString("Khaled");
            	    _delay_ms(100);




			} //end while





		return 0;
		} //end main

