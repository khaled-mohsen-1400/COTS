#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* array of tasks .. array of structs */

#define NULL (void *)0
static Tsak OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16priodicity , void (*Copy_ptr) (void))
{
	OS_Tasks[Copy_u8ID].priodicity = Copy_u16priodicity;
	OS_Tasks[Copy_u8ID].ptr = Copy_ptr;
}

void SOS_voidStart(void)
{
	/* Initializations */
	MSTK_voidInit();
	
	/* 1ms tick */
	/* HSE 8 MHz / 8 */
	MSTK_voidSetIntervalPeriodic(1000, SOS_voidScadular);
}

volatile u16 TickCounts = 0;
void SOS_voidScadular(void)
{
	
	for(u8 i = 0; i < NUMBER_OF_TASKS; i++)
	{
	   if(TickCounts % OS_Tasks[i].priodicity == 0)	
	   {
		   OS_Tasks[i].ptr();
	   }
	}
	TickCounts++;
}