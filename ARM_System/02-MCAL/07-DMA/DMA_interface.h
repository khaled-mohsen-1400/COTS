/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 15 september 2020           */
/* Version : V01                         */
/*****************************************/
#ifndef _DMA_INTERFACE_H
#define _DMA_INTERFACE_H

void HDMA_voidChannelInit(void);

void HDMA_voidChannelStart(u32 * Copy_pu32SourceAddress , u32 * Copy_pu32DestinationAddress , u16 Copy_u16BlockLength);

#endif