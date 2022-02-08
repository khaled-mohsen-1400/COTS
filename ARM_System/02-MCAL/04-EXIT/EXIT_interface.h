/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _EXIT_INTERFACE_H
#define _EXIT_INTERFACE_H


void EXIT_voidEnableEXIT(u8 Copy_u8Line);
void EXIT_voidDisableEXIT(u8 Copy_u8Line);
void EXIT_voidSwTrigger(u8 Copy_u8Line);
void EXIT_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

#endif