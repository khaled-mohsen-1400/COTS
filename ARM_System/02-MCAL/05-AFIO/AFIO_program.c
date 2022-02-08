/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void NAFIO_voidSetEXITConfigurations(u8 copy_u8Line , u8 copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	
	if(copy_u8Line <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		copy_u8Line = copy_u8Line - 4;
	}
	else if(copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		copy_u8Line = copy_u8Line - 8;
	}
	else if(copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		copy_u8Line = copy_u8Line - 12;
	}
	
	AFIO -> EXTICR[Local_u8RegIndex] &= ~((0b1111) << (copy_u8Line * 4) );
	AFIO -> EXTICR[Local_u8RegIndex] |= ((copy_u8PortMap) << (copy_u8Line * 4) );
}