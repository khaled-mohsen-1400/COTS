/************************************************/
/* Title       : EXTI Private file              */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#ifndef _EXTI_PRIV_H_
#define _EXTI_PRIV_H_


#define GICR 	(*((volatile u8 *)0x5B ) ) //PIE
#define GIFR 	(*((volatile u8 *)0x5A ) ) //PIF
#define MCUCSR 	(*((volatile u8 *)0x54 ) ) //INT2 MODE
#define MCUCR 	(*((volatile u8 *)0x55 ) ) //INT0 & INT MODE

#define EXTI_u8_LOW_LEVEL 0  // just any value for the macro
#define EXTI_u8_IOC 1
#define EXTI_u8_RISING_EDGE 2
#define EXTI_u8_FALLING_EDGE 3

#define EXTI_INT0  6 // INT0 enable pin in GICR register
#define ISC0 0       // INT0 Sense Control bit 0 in MCUCR register
#define ISC1 1       // INT0 Sense Control bit 0 in MCUCR register


#endif



