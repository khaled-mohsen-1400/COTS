/*
 * register.h
 *
 *  Created on: Aug 21, 2021
 *      Author: mosta
 */

#ifndef _MDIO_REGISTER_H_
#define _MDIO_REGISTER_H_



typedef struct
{
	u8 PIN;
	u8 DDR;
	u8 PORT;

}GPIO;

#define GPIOA 	((volatile GPIO *) 0x39)
#define GPIOB 	((volatile GPIO *) 0x36)
#define GPIOC 	((volatile GPIO *) 0x33)
#define GPIOD 	((volatile GPIO *) 0x30)


#endif
