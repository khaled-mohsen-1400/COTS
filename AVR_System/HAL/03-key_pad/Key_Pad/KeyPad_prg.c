/************************************************/
/* Title       : KeyPad program file            */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 17, 2021                   */
/************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "KeyPad_int.h"
#include "KeyPad_priv.h"
#include "KeyPad_config.h"

/* Connect pull up resistor or not */
void KeyPad_voidInit(void)
{
#if ( KEYPAD_u8_PULLUP == KEYPAD_u8_INTERNAL)

	DIO_vid_SetPinValue(KEYPAD_u8_ROW1 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_ROW2 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_ROW3 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_ROW4 , DIO_u8_HIGH);

#endif

}

/*This function shall return 16 bit variable
		indicating the status of each key */

u8 KeyPad_u16GetButton(void)
{
	Local_u8_Button = '\0';

	/*Apply sequence 0 */
	DIO_vid_SetPinValue(KEYPAD_u8_COL1 , DIO_u8_LOW);
	DIO_vid_SetPinValue(KEYPAD_u8_COL2 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL3 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL4 , DIO_u8_HIGH);

	Local_u8_Button = KeyPad_voidCheckRow(0);
	if(Local_u8_Button != '\0')
	return Local_u8_Button;

	/*Apply sequence 1 */
	DIO_vid_SetPinValue(KEYPAD_u8_COL1 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL2 , DIO_u8_LOW);
	DIO_vid_SetPinValue(KEYPAD_u8_COL3 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL4 , DIO_u8_HIGH);

    Local_u8_Button = KeyPad_voidCheckRow(1);
	if(Local_u8_Button != '\0')
	return Local_u8_Button;

	/*Apply sequence 2 */
	DIO_vid_SetPinValue(KEYPAD_u8_COL1 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL2 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL3 , DIO_u8_LOW);
	DIO_vid_SetPinValue(KEYPAD_u8_COL4 , DIO_u8_HIGH);

	Local_u8_Button = KeyPad_voidCheckRow(2);
	if(Local_u8_Button != '\0')
	return Local_u8_Button;

	/*Apply sequence 3 */
	DIO_vid_SetPinValue(KEYPAD_u8_COL1 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL2 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL3 , DIO_u8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_u8_COL4 , DIO_u8_LOW);

	Local_u8_Button = KeyPad_voidCheckRow(3);
	if(Local_u8_Button != '\0')
	return Local_u8_Button;
}


static u8 KeyPad_u8CheckRow(u8 Copy_Number)
{
	if(DIO_u8_GetPinValue(KEYPAD_u8_ROW1) == DIO_u8_LOW)
	{
		//SET_BIT(KeyPad_u16_Status , ( (0*4)+ Copy_Number ) ); //R1C1 0b0000000000000001 -> R1C2 0b0000000000000010 -> R1C3 0b0000000000000100 -> R1C4 0b0000000000001000
	    switch(Copy_Number)
		{
			case 0:
			return KEYPAD_u8_R1C1;
			break;
			
			case 1:
			return KEYPAD_u8_R1C2;
			break;
			
			case 2:
			return KEYPAD_u8_R1C3;
			break;
			
			case 3:
			return KEYPAD_u8_R1C4;
			break;
		}
	}
	if(DIO_u8_GetPinValue(KEYPAD_u8_ROW2) == DIO_u8_LOW)
	{
		//SET_BIT(KeyPad_u16_Status , ( (1*4)+ Copy_Number ) ); //R2C1 0b0000000000010000 -> R2C2 0b0000000000100000 -> R2C3 0b0000000001000000 -> R2C4 0b0000000010000000
	    switch(Copy_Number)
		{
			case 0:
			return KEYPAD_u8_R2C1;
			break;
			
			case 1:
			return KEYPAD_u8_R2C2;
			break;
			
			case 2:
			return KEYPAD_u8_R2C3;
			break;
			
			case 3:
			return KEYPAD_u8_R2C4;
			break;
		}	
	}
	if(DIO_u8_GetPinValue(KEYPAD_u8_ROW3) == DIO_u8_LOW)
	{
		//SET_BIT(KeyPad_u16_Status , ( (2*4)+ Copy_Number ) ); //R3C1 0b0000000100000000 -> R3C2 0b0000001000000000 -> R3C3 0b0000010000000000 -> R3C4 0b0000100000000000
	    switch(Copy_Number)
		{
			case 0:
			return KEYPAD_u8_R3C1;
			break;
			
			case 1:
			return KEYPAD_u8_R3C2;
			break;
			
			case 2:
			return KEYPAD_u8_R3C3;
			break;
			
			case 3:
			return KEYPAD_u8_R3C4;
			break;
		}	
	}
	if(DIO_u8_GetPinValue(KEYPAD_u8_ROW4) == DIO_u8_LOW)
	{
		//SET_BIT(KeyPad_u16_Status , ( (3*4)+ Copy_Number ) ); //R4C1 0b0001000000000000 -> R3C2 0b0010000000000000 -> R3C3 0b0100000000000000 -> R2C4 0b1000000000000000
	    switch(Copy_Number)
		{
			case 0:
			return KEYPAD_u8_R4C1;
			break;
			
			case 1:
			return KEYPAD_u8_R4C2;
			break;
			
			case 2:
			return KEYPAD_u8_R4C3;
			break;
			
			case 3:
			return KEYPAD_u8_R4C4;
			break;
		}	
	}
	
	return '\0';
}
