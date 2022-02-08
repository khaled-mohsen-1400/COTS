/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 16 september 2020           */
/* Version : V01                         */
/*****************************************/
#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void MSPI_voidInit(void);
void MSPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive);

#endif