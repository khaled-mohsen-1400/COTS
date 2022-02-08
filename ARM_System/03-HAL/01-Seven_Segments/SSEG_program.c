/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 16 August 2020              */
/* Version : V01                         */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSEG_interface.h"
#include "GPIO_interface.h"
#include "SSEG_config.h"

#define ARR_SIZE 10 
static u8 Ssegment_u8Array[ARR_SIZE]

void SSEG_voidInit(void)
{
 #if   SSEG_TYPE == SSEG_COMMON_ANODE
    // Keep this in case your 7-Segment common anode
	// ZERO ONE TWO THREE FOUR	FIVE SIX SEVEN EIGHT NINE in hex
	
      Ssegment_u8Array[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	  
      #elif SSEG_TYPE == SSEG_COMMON_CATHODE
	  Ssegment_u8Array[] = {0x3F, 0x09, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	  // Keep this in case your 7-Segment common cathode

      
 #endif
 
 		GPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_2MHZ_PP);
		
		GPIO_voidSetPinDirection(GPIOA, PIN8,  OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN9,  OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN13, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN14, OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(GPIOA, PIN15, OUTPUT_SPEED_2MHZ_PP);
}
	 

void SSEG_voidWrite(u8 Copy_u8_SSEG_ID, u8 Copy_u8_Data)
{
	swich (Copy_u8_SSEG_ID)
	{
		case SSEG_ONE:
        GPIO_voidSetByteValue(GPIOA, LEAST_BYTE, Ssegment_u8Array[Copy_u8_Data]);
		break;
		
		case SSEG_TWO:
		GPIO_voidSetByteValue(GPIOA, MOST_BYTE, Ssegment_u8Array[Copy_u8_Data]);
		break;
	}
}

