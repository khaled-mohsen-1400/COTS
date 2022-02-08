/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 28 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _STK_PRIVATE_H
#define _STK_PRIVATE_H

/* Register Definitions */

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
	
} STK_t;

#define STK                ((volatile STK_t *) 0xE000E010)

#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIODIC_INTERVAL  1
#define STK_AHP                 2
#define STK_AHP_OVER_8          3
#endif
                          