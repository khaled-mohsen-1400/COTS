/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 16 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _SSEG_INTERFACE_H
#define _SSEG_INTERFACE_H

/*seven segmnts ID input*/
#define SSEG_ONE  11
#define SSEG_TWO  22

void SSEG_voidInit(void);
void SSEG_voidWrite(u8 Copy_u8_SSEG_ID, u8 Copy_u8_Data);

#endif