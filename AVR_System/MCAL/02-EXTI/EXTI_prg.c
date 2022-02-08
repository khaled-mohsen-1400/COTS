/************************************************/
/* Title       : EXTI Program file              */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_priv.h" // before the configuration
#include "EXTI_config.h"


 /* Pointer to function */
void (* EXTI_CallBack) (void) ; // from the same type of ISR function void ..... (void)


void __vector_1(void) __attribute__((signal , used));
/*ISR function prototype ..
attribute gives command for compiler and linker ..
signal for linker to inform linker that the signal is by hardware ..
used to inform also that the ISR is used because it may be delete it as ISR is non callable function
(1) means jump to vector table for INT 0 */
void __vector_1(void)
{
	EXTI_CallBack() ;
	
}

void EXTI_voidInit(void)
{
		/*Set Mode*/
		#if(EXTI_u8_MODE == EXTI_u8_LOW_LEVEL)
			CLEAR_BIT(MCUCR , ISC0);
			CLEAR_BIT(MCUCR , ISC1);
		#elif(EXTI_u8_MODE == EXTI_u8_IOC)	
			SET_BIT(MCUCR , ISC0);
			CLEAR_BIT(MCUCR , ISC1);
		#elif(EXTI_u8_MODE == EXTI_u8_FALLING_EDGE)
			CLEAR_BIT(MCUCR , ISC0);
			SET_BIT(MCUCR , ISC1);
		#else(EXTI_u8_MODE == EXTI_u8_RISING_EDGE)
			SET_BIT(MCUCR , ISC0);
			SET_BIT(MCUCR , ISC1);
		#endif
		
		/*Disable interrupt*/
		CLEAR_BIT(GICR , EXTI_INT0); //PIE
		/*Clear Flag*/
		SET_BIT(GIFR , EXTI_INT0);   //PIF

}

void EXTI_voidSetCallBack(void (*Copy_ptr) (void)) // take the same type of ISR function void ..... (void) == function name at the main
{
	EXTI_CallBack = Copy_ptr ; // copy the function address from the main to be called and implemented in the prog.c
}

void EXTI_voidEnable(void)
{
	SET_BIT(GICR , EXTI_INT0); //PIE
}

void EXTI_voidDisable(void)
{
	CLEAR_BIT(GICR , EXTI_INT0); //PIE
}

