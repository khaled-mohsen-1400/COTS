/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 28 August 2020              */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void ( *MSTK_CallBack )( void );   /* define callback global variable */
static u8 MSTK_u8ModeOfInterval;
void MSTK_voidInit( void )
{

/* clock source selection */  
  #if   STK_CLOCK_SOURCE == STK_AHP
        SET_BIT(STK -> CTRL , 2);
  
  #elif STK_CLOCK_SOURCE == STK_AHP_OVER_8
        CLR_BIT(STK -> CTRL , 2);
}       

void MSTK_SetBusytWait( u32 Copy_u32Ticks );
{
	(STK -> LOAD) = Copy_u32Ticks;        /* load number of ticks */
	 SET_BIT(STK -> CTRL , 0);            /* Counter is enabled */
	while(! GIT_BIT(STK -> CTRL , 16) );  /* wait untill counter terminates */
	
	/* stop the timer */
	STK -> VAL  = 0;
}

void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) )
{
	(STK -> LOAD) = Copy_u32Ticks;                    /* load number of ticks */
     SET_BIT(STK -> CTRL , 0);	                      /* Counter is enabled */
	 MSTK_CallBack = Copy_Ptr;                        /* set callback function address */ 
	 MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;    /* select single mode */
	 SET_BIT(STK -> CTRL , 1);                        /* enable STK interrupt */
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) )
{
	(STK -> LOAD) = Copy_u32Ticks;                    /* load number of ticks */
     SET_BIT(STK -> CTRL , 0);	                      /* Counter is enabled */
	 MSTK_CallBack = Copy_Ptr;                        /* set callback function address */ 
	 MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL;  /* select periodic mode */
	 SET_BIT(STK -> CTRL , 1);                        /* enable STK interrupt */
}

void MSTK_voidStopInterval(void)
{
	CLR_BIT(STK -> CTRL , 0);	                      /* Counter is disabled */
	
    /* stop the timer */
	STK -> VAL  = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32ElapsedTime = 0;
	Local_u32ElapsedTime = STK -> LOAD  -  STK -> VAL;
	return Local_u32ElapsedTime;
}
u32  MSTK_u32GetRemainingTime(void)
{
    u32 Local_u32RemainingTime = 0;
	Local_u32RemainingTime = STK -> LOAD  -  STK -> VAL;
	return Local_u32RemainingTime;	
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		CLR_BIT(STK -> CTRL , 0);	                      /* Counter is disabled */
	
        /* stop the timer */
	    STK -> VAL  = 0;
	}
	
	MSTK_CallBack(); /* callback notification */
	Local_u8Temporary = GIT_BIT(STK -> CTRL , 16);
}