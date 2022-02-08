/************************************************/
/* Title       : ADC Program file               */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_priv.h"
#include "ADC_config.h"


void (*CallBackPointer) (void);

void ADC_voidInit(void)
{
	/*Set ref volatage*/
#if ADC_Mode_Voltage ==ADC_AVCC

	SET_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);

#elif ADC_Mode_Voltage == ADC_Internal
	SET_BIT(ADMUX , 6);
	SET_BIT(ADMUX , 7);

#elif ADC_Mode_Voltage == ADC_Aref

	CLEAR_BIT(ADMUX , 6);
	CLEAR_BIT(ADMUX , 7);


#endif 

	/*prescaler value*/

#if ADC_Prescaler_Option == ADC_Prescaler_2

	CLEAR_BIT(ADCSRA , 0 );
	CLEAR_BIT(ADCSRA , 1 );
	CLEAR_BIT(ADCSRA , 2 );

#elif ADC_Prescaler_Option == ADC_Prescaler_4
	CLEAR_BIT(ADCSRA , 0 );
	SET_BIT(ADCSRA , 1 );
	CLEAR_BIT(ADCSRA , 2 );


#elif ADC_Prescaler_Option == ADC_Prescaler_8

	SET_BIT(ADCSRA , 0 );
	SET_BIT(ADCSRA , 1 );
	CLEAR_BIT(ADCSRA , 2 );

#elif ADC_Prescaler_Option == ADC_Prescaler_16

	CLEAR_BIT(ADCSRA , 0 );
	CLEAR_BIT(ADCSRA , 1 );
	SET_BIT(ADCSRA , 2 );

#elif ADC_Prescaler_Option == ADC_Prescaler_32

	SET_BIT(ADCSRA , 0 );
	CLEAR_BIT(ADCSRA , 1 );
	SET_BIT(ADCSRA , 2 );

#elif ADC_Prescaler_Option == ADC_Prescaler_64

	CLEAR_BIT(ADCSRA , 0 );
	SET_BIT(ADCSRA , 1 );
	SET_BIT(ADCSRA , 2 );



#elif ADC_Prescaler_Option == ADC_Prescaler_128

	SET_BIT(ADCSRA , 0 );
	SET_BIT(ADCSRA , 1 );
	SET_BIT(ADCSRA , 2 );

#endif


	/* Eight bit mode which is Mode Left adusted  */
#if ADC_Mode == Eight_Bit_Mode
	SET_BIT(ADMUX , 5);
	/* Ten bit mode which is right adjusted */
#else
	CLEAR_BIT(ADMUX , 5);
#endif
	/*Clear interrupt flag and disable interrupt*/
	SET_BIT(ADCSRA , 4);
	CLEAR_BIT(ADCSRA , 3);

	/*Enable ADC Module*/
	SET_BIT(ADCSRA , 7);

}

void ADC_voidEnableInt(void)
{
	SET_BIT(ADCSRA , 3);
}

void ADC_voidDisableInt(void)
{
	CLEAR_BIT(ADCSRA , 3);
}

void ADC_voidSetCallBack( void (*Copy_Ptr) (void) )
{
	CallBackPointer = Copy_Ptr ;
}

void ADC_voidEnableADC(void)
{
	SET_BIT(ADCSRA , 7);
}

void ADC_voidDisableADC(void)
{
	CLEAR_BIT(ADCSRA , 7);
}

#if ADC_Mode == Eight_Bit_Mode

u8 ADC_u8GetConversionValue(u8 Channel)
{
	ADMUX &= 0b11100000 ;
	ADMUX |= Channel ;

	/*Start Coversion*/
	SET_BIT(ADCSRA , 6);

   // another way for the end of conversion 
   while(GET_BIT(ADCSRA , 6) == 1);
   return ADCH ;
}

u8 ADC_u8GetLastValue(void)
{
	return ADCH;
}

/* 10-bit mode which is Right Adjusted */

#else

u16 ADC_u16GetConversionValue(u8 Channel)
{
	u8 LOW , HIGH ;
	u16 data;
	//u16 result ;
	ADMUX &= 0b11100000 ;
	ADMUX |= Channel ;
	/*start convertion*/
	SET_BIT(ADCSRA , 6);
	
		while(GET_BIT(ADCSRA , 6) == 1);
		LOW = ADCL ;
		HIGH = ADCH ;
	    data = ( ( ( HIGH & 0b00000011)<<8 ) | LOW  ) ;
		return data;


}

u16 ADC_u16GetLastValue(void)
{
	u16 result ;
	u8 LOW ;
	u8 HIGH ;
	LOW = ADCL ;
	HIGH = ADCH ;
	result = ( ( (HIGH & 0b00000011)<<8 )| LOW  ) ;
	return result ;
}

#endif




void __vector_16(void) __attribute__((signal , used));
void __vector_16(void)
{
	CallBackPointer();
}

