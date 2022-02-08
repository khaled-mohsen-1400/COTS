/*
 * TIMER0.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Khaled
 */

/*#include "STD_TYPES.h"
#include "DIO_int.h"
#include "Timer_int.h"
#include "GIE_int.h"



#define OV_CNT 199
#define INT_VAL 224

volatile u16 counter = 0;
volatile u8 flag = 0;


void func(void)
{
	counter++;
	if(counter == 1954)
	{
	counter = 0;
	TIMER0_void_SetTimerReg(INT_VAL);
	if(flag == 0)
		flag = 1;
	else
		flag=0;

	}
}
int main()
{
    DIO_vid_Init();
    TIMER0_void_Init();
	TIMER0_void_SetTimerReg(INT_VAL);
	TIMER0_void_SetOVCallBack(func);
	TIMER0_void_EnableOVInt();
	GIE_voidEnable();

while(1)
{
 if(flag == 0)
	 DIO_vid_SetPinValue(DIO_u8_PIN_0 , DIO_u8_HIGH);
 else
	 DIO_vid_SetPinValue(DIO_u8_PIN_0 , DIO_u8_LOW);
}

}
*/
