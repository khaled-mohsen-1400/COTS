/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXIT_interface.h"
#include "EXIT_private.h"
#include "EXIT_config.h"


void EXIT_voidEnableEXIT(u8 Copy_u8Line)
{
    SET_BIT(EXIT -> FTSR , EXIT_LINE);
}

void EXIT_voidDisableEXIT(u8 Copy_u8Line)
{
	CLR_BIT(EXIT -> FTSR , EXIT_LINE);
}

void EXIT_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXIT -> SWIER , EXIT_LINE);
}

void EXIT_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	    case RISING    :  SET_BIT(EXIT -> RTSR , EXIT_LINE);  break;
		case FALLING   :  SET_BIT(EXIT -> FTSR , EXIT_LINE);  break;
		case ON_CHANGE :  SET_BIT(EXIT -> RTSR , EXIT_LINE);
                          SET_BIT(EXIT -> FTSR , EXIT_LINE);  break;
	}
}