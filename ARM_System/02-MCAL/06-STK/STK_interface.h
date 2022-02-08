/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 28 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

void MSTK_voidInit( void );
void MSTK_SetBusytWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif