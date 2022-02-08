/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 14 september 2020           */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTO_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;
	for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
	{
		/* send bit by bit starting from MSB */	
		Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_s8Counter);
		
		GPIO_voidSetPinValue(HSTP_SERIAL_DATA , Local_u8Bit);
		
		/* send pulse to shift clock */	
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK , GPIO_HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK , GPIO_LOW);
	    STK_voidSetBusyWait(1);
	}
	
		/* send pulse to store clock */	
		GPIO_voidSetPinValue(HSTP_STORE_CLOCK , GPIO_HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(HSTP_STORE_CLOCK , GPIO_LOW);
	    STK_voidSetBusyWait(1);
  
}