/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/

#ifndef SSEGMENT_INT_H_
#define SSEGMENT_INT_H_

/*
* function to choose the ssegment then write the value you want to be shown
* If you want ssegment far away from the LCD  just type SSEGMENT_ONE
* If you want ssegment near from LCD just type SSEGMENT_TWO
*
*/

#define SSEGMENT_ONE 10
#define SSEGMENT_TWO 20


void Ssegment_void_WriteNum(u8 Copy_u8_SsegmentNum , u8 Copy_u8_Num);
void Ssegment_void_Clear(u8 Copy_u8_SsegmentNum);

#endif /* SSEGMENT_INT_H_ */
