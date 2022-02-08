/*
 * DIO_prog.c
 *
 *  Created on: Aug 22, 2021
 *      Author: mostafa
 */


#include "stdtypes.h"
#include "MDIO_priv.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "MDIO_register.h"



void DIO_void_SETPORT_DIR(u8 ARG_u8_Port,u8 ARG_u8_Direction)
{
	switch(ARG_u8_Port)
	{
		case DIO_PORT_A:
		{
			GPIOA->DDR = ARG_u8_Direction;
			break;
		};
		case DIO_PORT_B:
				{
					GPIOB->DDR = ARG_u8_Direction;
					break;
				};
		case DIO_PORT_C:
				{
					GPIOC->DDR = ARG_u8_Direction;
					break;
				};
		case DIO_PORT_D:
				{
					GPIOD->DDR = ARG_u8_Direction;
					break;
				};

		default:
			break;
	}

}
void DIO_void_SETPORT_VALUE(u8 ARG_u8_Port,u8 ARG_u8_value)
{
	switch(ARG_u8_Port)
		{
			case DIO_PORT_A:
			{
				GPIOA->PORT = ARG_u8_value;
				break;
			};
			case DIO_PORT_B:
					{
						GPIOB->PORT = ARG_u8_value;
						break;
					};
			case DIO_PORT_C:
					{
						GPIOC->PORT = ARG_u8_value;
						break;
					};
			case DIO_PORT_D:
					{
						GPIOD->PORT = ARG_u8_value;
						break;
					};

			default:
				break;
		}
}
u32 DIO_u8_GETPORT(u8 ARG_u8_Port)
{
	u32 return_u32_PORT;

	switch(ARG_u8_Port)
			{
				case DIO_PORT_A:
				{
							return_u32_PORT = GPIOA->PIN;
							break;
				};
				case DIO_PORT_B:
						{
							return_u32_PORT = GPIOB->PIN;
							break;
						};
				case DIO_PORT_C:
						{
							return_u32_PORT = GPIOC->PIN;
							break;
						};
				case DIO_PORT_D:
						{
							return_u32_PORT = GPIOD->PIN;
							break;
						};

				default:break;
			}
	return return_u32_PORT;
}
u8 DIO_u8_GETPIN(u8 ARG_u8_Pinnum)
{
	u8 return_u8_PIN;

	if( (-1<ARG_u8_Pinnum) && (ARG_u8_Pinnum<8))
	{
		return_u8_PIN = GETBIT(GPIOA->PIN,ARG_u8_Pinnum);
	}

	else if( (7<ARG_u8_Pinnum) && (ARG_u8_Pinnum<16))
	{
		return_u8_PIN = GETBIT(GPIOB->PIN,ARG_u8_Pinnum);
	}

	else if( (15<ARG_u8_Pinnum) && (ARG_u8_Pinnum<24))
	{
		return_u8_PIN = GETBIT(GPIOC->PIN,ARG_u8_Pinnum);
	}
	else if( (23<ARG_u8_Pinnum) && (ARG_u8_Pinnum<32))
	{
		return_u8_PIN = GETBIT(GPIOD->PIN,ARG_u8_Pinnum);
	}
	return return_u8_PIN;
}
void DIO_void_SETPIN(u8 ARG_u8_Pinnum,u8 ARG_u8_value)
{
	if( (-1<ARG_u8_Pinnum) && (ARG_u8_Pinnum<8))
		{
			SETBIT(GPIOA->PORT,ARG_u8_value);
		}

		else if( (7<ARG_u8_Pinnum) && (ARG_u8_Pinnum<16))
		{
			SETBIT(GPIOB->PORT,ARG_u8_value);
		}

		else if( (15<ARG_u8_Pinnum) && (ARG_u8_Pinnum<24))
		{
			SETBIT(GPIOC->PORT,ARG_u8_value);
		}
		else if( (23<ARG_u8_Pinnum) && (ARG_u8_Pinnum<32))
		{
			SETBIT(GPIOD->PORT,ARG_u8_value);
		}
}
