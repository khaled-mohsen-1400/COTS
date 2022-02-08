/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 16 september 2020           */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void);
void MSPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive)
{
	/* clear for slave select pin */
	GPIO_SetPinValue
}