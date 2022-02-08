/*
 * STEPPER_MOTOR_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng.Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#include "DIO_int.h"
#include "STEPPER_MOTOR_int.h"

u8 Local_u8_Counter;

void Smotor_vid_setSpeed_Direc(u8 Copy_u8_Speed , u8 Copy_u8_Direction)
{
  if(Copy_u8_Direction == 1 && Copy_u8_Speed == 1)
  {
		for(Local_u8_Counter = 0 ;Local_u8_Counter < 512 / 2 ;Local_u8_Counter++)
		{
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14, DIO_u8_HIGH);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		} //end for
  }

     if(Copy_u8_Direction == 0 && Copy_u8_Speed == 0)
  {
		for(Local_u8_Counter = 0 ;Local_u8_Counter < 512 / 2 ;Local_u8_Counter++)
		{
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_HIGH);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
		_delay_ms(2);
		DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
		DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_HIGH);
		_delay_ms(2);
		} //end for
  }

}

void Smotor_vid_int()
{
	DIO_vid_SetPinValue(DIO_u8_PIN_11 , DIO_u8_LOW);
	DIO_vid_SetPinValue(DIO_u8_PIN_12 , DIO_u8_LOW);
	DIO_vid_SetPinValue(DIO_u8_PIN_13 , DIO_u8_LOW);
	DIO_vid_SetPinValue(DIO_u8_PIN_14 , DIO_u8_LOW);
}
