/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 19 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber);
void MNVIC_void_Init(void);
void MNVIC_voidSetPriority(u8 Copy_s8IntID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );

#endif