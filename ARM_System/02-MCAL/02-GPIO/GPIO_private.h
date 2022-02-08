/******************************************/
/* Author  : Khaled Mohsen                */
/* Date    : 12 August 2020               */
/* Version : V01                          */
/******************************************/
#ifndef _GPIO_PRIVATE_H
#define _GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS   0x40010800
#define GPIOB_BASE_ADDRESS   0x40010C00
#define GPIOC_BASE_ADDRESS   0x40011000

/* Register Definitions */

/* Port A registers */
#define GPIOA_CRL               *((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH               *((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR               *((u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR               *((u32*)(GPIOA_BASE_ADDRESS + 0x0C))

/* Port A registers */
#define GPIOB_CRL               *((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH               *((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR               *((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR               *((u32*)(GPIOB_BASE_ADDRESS + 0x0C))

/* Port A registers */
#define GPIOC_CRL               *((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH               *((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR               *((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR               *((u32*)(GPIOC_BASE_ADDRESS + 0x0C))



#endif
