/*
 * DIO_int.h
 *
 *  Created on: Aug 22, 2021
 *      Author: mosta
 */

#ifndef DIO_INT_H_
#define DIO_INT_H


#define DIO_PORT_A	0
#define DIO_PORT_B	1
#define DIO_PORT_C	2
#define DIO_PORT_D	3

#define DIO_PIN_0	0
#define DIO_PIN_1	1
#define DIO_PIN_2	2
#define DIO_PIN_3	3
#define DIO_PIN_4	4
#define DIO_PIN_5	5
#define DIO_PIN_6	6
#define DIO_PIN_7	7


#define DIO_PIN_24 24
#define DIO_PIN_25 25

#define DIO_HIGH	1
#define DIO_LOW		0



void DIO_void_SETPORT_DIR(u8 ARG_u8_Port,u8 ARG_u8_Direction);

void DIO_void_SETPORT_VALUE(u8 ARG_u8_Port,u8 ARG_u8_value);

u32 DIO_u8_GETPORT(u8 ARG_u8_Port);

u8 DIO_u8_GETPIN(u8 ARG_u8_Pinnum);

void DIO_void_SETPIN(u8 ARG_u8_Pinnum,u8 ARG_u8_value);



#endif
