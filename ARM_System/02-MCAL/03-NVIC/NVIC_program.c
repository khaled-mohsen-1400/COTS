/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 19 August 2020              */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_void_Init(void)
{
	#define SCB_AIRCR     *((u32*)(0xE000ED00 + 0x00C))
	SCB_AIRCR = MNVIC_GROUP_2_SUB_2;
}

void MNVIC_voidSetPriority(u8 Copy_s8IntID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{							/*0x05FA0400 3 Group & 1 sub priority*/
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority << ((NO_OF_GROUPS_SUB - 0x05FA0300)/256));
	/* core peripheral 			*/
	if(Copy_s8IntID < 0)
	{

	}
	/* external peripheral		*/ /*EXTI0 = 6*/
	else if(Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4 ;
	}
	SCB_AIRCR = NO_OF_GROUPS_SUB ;
}

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{   
	if( Copy_u8IntNumber <= 31 )
	{
		FAST_SET_BIT(NVIC_ISER0 , Copy_u8IntNumber); // zero has no effect
	}
	elseif( Copy_u8IntNumber <= 59 )
	{   
	    Copy_u8IntNumber = Copy_u8IntNumber - 32;
		FAST_SET_BIT(NVIC_ISER1 , Copy_u8IntNumber);
	}
	else
	{
		/*return error*/
	}
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{   
	if( Copy_u8IntNumber <= 31 )
	{
		FAST_SET_BIT(NVIC_ICER0 , Copy_u8IntNumber); // zero has no effect
	}
	elseif( Copy_u8IntNumber <= 59 )
	{   
	    Copy_u8IntNumber = Copy_u8IntNumber - 32;
		FAST_SET_BIT(NVIC_ICER1 , Copy_u8IntNumber);
	}
	else
	{
		/*return error*/
	}
}

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{   
	if( Copy_u8IntNumber <= 31 )
	{
		FAST_SET_BIT(NVIC_ISPR0 , Copy_u8IntNumber); // zero has no effect
	}
	elseif( Copy_u8IntNumber <= 59 )
	{   
	    Copy_u8IntNumber = Copy_u8IntNumber - 32;
		FAST_SET_BIT(NVIC_ISPR1 , Copy_u8IntNumber);
	}
	else
	{
		/*return error*/
	}
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{   
	if( Copy_u8IntNumber <= 31 )
	{
		FAST_SET_BIT(NVIC_ICPR0 , Copy_u8IntNumber); // zero has no effect
	}
	elseif( Copy_u8IntNumber <= 59 )
	{   
	    Copy_u8IntNumber = Copy_u8IntNumber - 32;
		FAST_SET_BIT(NVIC_ICPR1 , Copy_u8IntNumber);
	}
	else
	{
		/*return error*/
	}
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{   
    u8 Local_u8Result;
	if( Copy_u8IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT(NVIC_IAPR0 , Copy_u8IntNumber);
	}
	elseif( Copy_u8IntNumber <= 59 )
	{   
	    Copy_u8IntNumber = Copy_u8IntNumber - 32;
		Local_u8Result = GET_BIT(NVIC_IAPR1 , Copy_u8IntNumber);
	}
	else
	{
		/*return error*/
	}
	
	return Local_u8Result;
}

