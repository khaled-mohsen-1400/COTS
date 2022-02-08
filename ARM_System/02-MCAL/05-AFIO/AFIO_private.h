/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

/* Register Definitions */

typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;
	
} AFIO_t;

#define AFIO          ((volatile AFIO_t *) 0x40010000)





#endif
                          