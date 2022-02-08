/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 31 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _LEDMRX_PRIVATE_H
#define _LEDMRX_PRIVATE_H

/* Register Definitions */

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
	
} STK_t;

#define STK                ((volatile STK_t *) 0xE000E010)
#define STK_MAX_TICKS      16777216
#endif
                          