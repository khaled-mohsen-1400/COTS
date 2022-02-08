/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 8 August 2020               */
/* Version : V01                         */
/*****************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

#define RCC_GPIOA_PER_EN  2
#define RCC_GPIOB_PER_EN  3
#define RCC_GPIOC_PER_EN  4

void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidInitSysClock(void);

#endif
