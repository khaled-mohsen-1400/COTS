/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 15 september 2020           */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void HDMA_voidChannelInit(void)
{
	/*  
	  1- memory to memory
	  2- very highvideo
	  3- source size 
	  4- destination size
	  5- MINC , PINC are activated
	  6- no circular
	  7- direction
	  8- transfer interrupt enable
	*/
	
	#if CHANNEL_ID == 1
	DMA -> Channel[0].CCR = 
}

void HDMA_voidChannelStart(u32 * Copy_pu32SourceAddress , u32 * Copy_pu32DestinationAddress , u16 Copy_u16BlockLength)
{
	/* make sure that channel is disabled */
	CLR_BIT(DMA -> Channel[0].CCR , 0);
	/* Write the address  */
	DMA -> Channel[0].CPAR = Copy_pu32SourceAddress;
	DMA -> Channel[0].CMAR = Copy_pu32DestinationAddress;
	
	/* block length */
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;	
	
		/* enable channel */
	SET_BIT(DMA -> Channel[0].CCR , 0);
}