/************************************************/
/* Title       : ADC Main file                  */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "ADC_int.h"

//u8 x = 3 ;
void LCD_intgerToString(u8 data);
int main(void)
{
	u8  MyPointer ;
	u16 Analog ;
	DIO_vid_Init();
	ADC_voidInit();
	LCD_vidInit();


	while(1)
	{


			 ADC_u8GetConversionValue(0 , &MyPointer);

			 //Log_voidPrintNumber(MyPointer);

			 Analog = (u16) (   (u32)(  (u32)MyPointer * (u32)500) / (u16)256 );
			 LCD_intgerToString(Analog);
			_delay_ms(2000);
			LCD_vidClearScreen();


	}
	return 0 ;

}
void LCD_intgerToString(u8 data)
{
   u8 buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
   LCD_vidWriteString(buff);
}
