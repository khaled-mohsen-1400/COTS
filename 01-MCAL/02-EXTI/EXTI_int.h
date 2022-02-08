/************************************************/
/* Title       : EXTI Interface file            */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#ifndef _EXTI_INT_H_

#define _EXTI_INT_H_


void EXTI_voidInit(void);

void EXTI_voidSetCallBack(void (*Copy_ptr) (void));

void EXTI_voidEnable(void); //PIE

void EXTI_voidDisable(void); //PIE


#endif