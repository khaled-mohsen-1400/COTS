/*****************************************/
/* Title   : SSEG interface file         */
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/

#ifndef SSEG_INT_H_
#define SSEG_INT_H_

#define NUMBER_ZERO 0
#define NUMBER_ONE 1
#define NUMBER_TWO 2
#define NUMBER_ONE 1
#define NUMBER_ONE 1
#define NUMBER_ONE 1
#define NUMBER_ONE 1
#define NUMBER_NINE 9

#define HIGH    1
#define LOW     0

#define SEG_A   0
#define SEG_B   1
#define SEG_C   1


void SSEG_void_SetNum(u8 Copy_u8_Number);
void SSEG_void_SetSeg(u8 Copy_u8_Segment , u8 Copy_u8_State);
void SSEG_void_Clear(void);



#endif