
#include"SSEG_int.h"
#include"DIO_int.h"
#include"SSEG_config.h"
#include"SSEG_prive.h"

void SSEG_void_SetNum(u8 Copy_u8_Number)
{
	switch(Copy_u8_Number)
	{
		case NUMBER_ZERO:
		DIO_vidSetPort(DIO_PORTA,ZERO);
		break;
		
	}
}

void SSEG_void_SetSeg(u8 Copy_u8_Segment , u8 Copy_u8_State)
{
	switch(Copy_u8_Segment)
	{
		case SEG_A:
		DIO_vid_SetPinValue(DIO_PORTA,SEG_A,Copy_u8_State);
		break;
	}
}

void SSEG_void_Clear(void)
{
	SSEG_void_SetNum(RESET);
}