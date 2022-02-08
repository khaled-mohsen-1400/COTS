/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 31 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _LEDMRX_INTERFACE_H
#define _LEDMRX_INTERFACE_H

void NSTK_voidInit( void );
void NSTK_SetBusytWait( u32 Copy_u32Ticks );
void NSTK_voidSetIntervalSingle( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) );
void NSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void ( *Copy_Ptr ) (void) );
void NSTK_voidStopInterval(void);
u32  NSTK_u32GetElapsedTime(void);
u32  NSTK_u32GetRemainingTime(void);

#endif