/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 19 August 2020              */
/* Version : V01                         */
/*****************************************/
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

/* Register Definitions */
#define NVIC_BASE_ADDRESS            0xE000E100

#define NVIC_ISER0                   *((u32*)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1                   *((u32*)(NVIC_BASE_ADDRESS + 0x004))
#define NVIC_ICER0                   *((u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1                   *((u32*)(NVIC_BASE_ADDRESS + 0x084))
#define NVIC_ISPR0                   *((u32*)(NVIC_BASE_ADDRESS + 0x100)) // for testing and depugging
#define NVIC_ISPR1                   *((u32*)(NVIC_BASE_ADDRESS + 0x104)) // for testing and depugging
#define NVIC_ICPR0                   *((u32*)(NVIC_BASE_ADDRESS + 0x180)) // for testing and depugging
#define NVIC_ICPR1                   *((u32*)(NVIC_BASE_ADDRESS + 0x184)) // for testing and depugging
#define NVIC_IAPR0                   *((u32*)(NVIC_BASE_ADDRESS + 0x200)) //read only
#define NVIC_IAPR1                   *((u32*)(NVIC_BASE_ADDRESS + 0x204)) //read only

#define NVIC_IPR                     ((u8*)(NVIC_BASE_ADDRESS + 0x400))


#define MNVIC_GROUP_4_SUB_0          0x05FA0300
#define MNVIC_GROUP_3_SUB_2          0x05FA0400
#define MNVIC_GROUP_2_SUB_2          0x05FA0500
#define MNVIC_GROUP_1_SUB_3          0x05FA0600
#define MNVIC_GROUP_0_SUB_4          0x05FA0700

#endif
                          