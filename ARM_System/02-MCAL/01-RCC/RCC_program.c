/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 8 August 2020               */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

//  0000 0000  31 <- 16  15 <- 0
void RCC_voidInitSysClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	      RCC_CR   = 0x00010000;
		  RCC_CFGR = 0x00000001;
		  
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	       RCC_CR   = 0x00050000;
		   RCC_CFGR = 0x00000001;
		  
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	       RCC_CR   = 0x00000001; //Enable HSI
		   RCC_CFGR = 0x00000000;
		   
    #elif  RCC_CLOCK_TYPE == RCC_PLL
	   #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	              RCC_CFGR = 0x00000002; // HSI / 2 input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01000001; //Enable HSI & PLL 
				  
             #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00040002; // HSI / 2 input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01000001; //Enable HSI & PLL 
				  
	         #endif

	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	              RCC_CFGR = 0x00020002; // HSE / 2 input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 	 
				  
	         #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00060002; // HSE / 2 input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 		 

	         #endif
	   
	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	              RCC_CFGR = 0x00000002; // HSE input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 
				  
	   	     #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00040002; // HSE input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 				 

	         #endif
	   
	   #endif
	   
	#else  
		#error("You chosed wrong clock type")
	
	#endif
	
}

void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31) /*Input Validation*/
	{
	  switch (Copy_u8BusId)
	  {
		  case RCC_AHB   : SET_BIT(RCC_AHBENR, Copy_u8PerId); break;
		  case RCC_APB1  : SET_BIT(RCC_APB1ENR,Copy_u8PerId); break;
		  case RCC_APB2  : SET_BIT(RCC_APB2ENR,Copy_u8PerId); break;
	  }
		
	}
	else
	{
		/* Return Error */ 
	}
	
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31) /*Input Validation*/
	{
	  switch (Copy_u8BusId)
	  {
		  case RCC_AHB   : CLR_BIT(RCC_AHBENR, Copy_u8PerId); break;
		  case RCC_APB1  : CLR_BIT(RCC_APB1ENR,Copy_u8PerId); break;
		  case RCC_APB2  : CLR_BIT(RCC_APB2ENR,Copy_u8PerId); break;
	  }
		
	}
	else
	{
		/* Return Error */ 
	}
	
}

void RCC_voidInitSysClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	      RCC_CR   = 0x00010000;
		  RCC_CFGR = 0x00000001;
		  
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	       RCC_CR   = 0x00050000;
		   RCC_CFGR = 0x00000001;
		  
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	       RCC_CR   = 0x00000001; //Enable HSI
		   RCC_CFGR = 0x00000000;
		   
    #elif  RCC_CLOCK_TYPE == RCC_PLL
	   #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	              RCC_CFGR = 0x00000002; // HSI / 2 input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01000001; //Enable HSI & PLL 
				  
             #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00040002; // HSI / 2 input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01000001; //Enable HSI & PLL 
				  
	         #endif

	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	              RCC_CFGR = 0x00020002; // HSE / 2 input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 	 
				  
	         #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00060002; // HSE / 2 input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 		 

	         #endif
	   
	   #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	              RCC_CFGR = 0x00000002; // HSE input PLL * 2 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 
				  
	   	     #if   RCC_PLL_MUL_VAL == 3
	              RCC_CFGR = 0x00040002; // HSE input PLL * 3 when PLL is disabled till now & PLL system clock is selected
	              RCC_CR   = 0x01010000; //Enable HSE & PLL 				 

	         #endif
	   
	   #endif
	   
	#else  
		#error("You chosed wrong clock type")
	
	#endif
	
}
