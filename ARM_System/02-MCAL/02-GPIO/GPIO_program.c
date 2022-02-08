/******************************************/
/* Author  : Khaled Mohsen                */
/* Date    : 15 August 2020               */
/* Version : V01                          */
/******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
   switch(copy_u8Port)
   {
	   case GPIOA :
	               if(copy_u8Pin <= 7)
				   {
					   GPIOA_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOA_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
				   else if(copy_u8Pin <= 15)
				   {
					   copy_u8Pin = copy_u8Pin - 8;
					   PIOA_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOA_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
				   break;
				   
	   case GPIOB :
	               if(copy_u8Pin <= 7)
				   {
					   GPIOB_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOB_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
				   else if(copy_u8Pin <= 15)
				   {
					   copy_u8Pin = copy_u8Pin - 8;
					   GPIOB_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOB_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
				   break;
				   
	   case GPIOC :
	               if(copy_u8Pin <= 7)
				   {
					   GPIOC_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOC_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
				   else if(copy_u8Pin <= 15)
				   {
					   copy_u8Pin = copy_u8Pin - 8;
					   GPIOC_CRL &= ~ ((0b1111) << (copy_u8Pin* 4));
					   GPIOC_CRL |= ((copy_u8Mode) << (copy_u8Pin) * 4));
				   }
                   break;				   
   } //end switch   
} //end function



void GPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
   switch(copy_u8Port)
   {
	   case GPIOA :
	               if(copy_u8Value == GPIO_HIGH)
				   {
					   SET_BIT(GPIOA_ODR , copy_u8Pin);
				   }
				   else if(copy_u8Value == GPIO_LOW)
				   {
                       CLR_BIT(GPIOA_ODR , copy_u8Pin);
				   }
				   break;
				   
	   case GPIOB :
	               if(copy_u8Value == GPIO_HIGH)
				   {
					   SET_BIT(GPIOB_ODR , copy_u8Pin);
				   }
				   else if(copy_u8Value == GPIO_LOW)
				   {
                       CLR_BIT(GPIOB_ODR , copy_u8Pin);
				   }
				   break;
				   
	   case GPIOC :
	               if(copy_u8Value == GPIO_HIGH)
				   {
					   SET_BIT(GPIOC_ODR , copy_u8Pin);
				   }
				   else if(copy_u8Value == GPIO_LOW)
				   {
                       CLR_BIT(GPIOC_ODR , copy_u8Pin);
				   }
				   break;
				   
   } //end switch	
}

void GPIO_voidSetByteValue(u8 copy_u8Port, u8 copy_u8ByteLocation, u8 copy_u8Value)
{
   switch(copy_u8Port)
   {
	   case GPIOA :
	               if(copy_u8ByteLocation == MOST_BYTE)
				   {
					   GPIOA_ODR &= ~ (0xFF << 8);
					   GPIOA_ODR |= (copy_u8Value << 8);
				   }
				   else if(copy_u8ByteLocation == LEAST_BYTE)
				   {
					   GPIOA_ODR &= ~ (0xFF);
					   GPIOA_ODR |= (copy_u8Value);
				   }
				   break;
				   
	   case GPIOB :
	               if(copy_u8ByteLocation == MOST_BYTE)
				   {
					   GPIOB_ODR &= ~ (0xFF << 8);
					   GPIOB_ODR |= (copy_u8Value << 8);
				   }
				   else if(copy_u8ByteLocation == LEAST_BYTE)
				   {
					   GPIOB_ODR &= ~ (0xFF);
					   GPIOB_ODR |= (copy_u8Value);
				   }
				   break;
				   
   } //end switch	
}

u8 GPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{  
   u8 Local_u8Result = 0;
   
   switch(copy_u8Port)
   {
	   case GPIOA :
	               Local_u8Result = GET_PIN(GPIOA_IDR, copy_u8Pin);
				   break;
				   
	   case GPIOB :
	               Local_u8Result = GET_PIN(GPIOB_IDR, copy_u8Pin);
				   break;
				   
	   case GPIOC :
	               Local_u8Result = GET_PIN(GPIOC_IDR, copy_u8Pin);
				   break;
				   
   } //end switch	
   return Local_u8Result;
}