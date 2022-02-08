/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 31 August 2020              */
/* Version : V01                         */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "LEDMRX_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN    , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN    , OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinDirection(LEDMRX_COLUMN0_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN1_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN2_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN3_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN4_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN5_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN6_PIN , OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LEDMRX_COLUMN7_PIN , OUTPUT_SPEED_2MHZ_PP);

}

void HLEDMRX_voidDisPlay(u8 *Copy_u8Data)
{
	while(1)
    {
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[0] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );
	
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[1] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );
	
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[2] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );

	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[3] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );	
	
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[4] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );
	
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[5] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );
	
	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[6] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );

	/* disable all columns */
    HLEDMRX_voidDisableAllColumns();
	/* write data on rows */
	HLEDMRX_voidSetRowValue( Copy_u8Data[7] );
	/* enable column 0 */
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN , GPIO_LOW);
	/* delay 2.5 ms */
	MSTK_SetBusytWait( 2500 );	
	}
}     

void HLEDMRX_voidDisableAllColumns(void)
{
	GPIO_voidSetPinValue(LEDMRX_COLUMN0_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN1_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN2_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN3_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN4_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN5_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN6_PIN , GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMRX_COLUMN7_PIN , GPIO_HIGH);
}  

void HLEDMRX_voidSetRowValue(u8 Copy_u8Value)
{
	u8 Local_u8BIT = 0;
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 0);
	GPIO_voidSetPinValue(LEDMRX_ROW0_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 1);
	GPIO_voidSetPinValue(LEDMRX_ROW1_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 2);
	GPIO_voidSetPinValue(LEDMRX_ROW2_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 3);
	GPIO_voidSetPinValue(LEDMRX_ROW3_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 4);
	GPIO_voidSetPinValue(LEDMRX_ROW4_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 5);
	GPIO_voidSetPinValue(LEDMRX_ROW5_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 6);
	GPIO_voidSetPinValue(LEDMRX_ROW6_PIN , Local_u8BIT);
	
	Local_u8BIT = GIT_BIT(Copy_u8Value , 7);
	GPIO_voidSetPinValue(LEDMRX_ROW7_PIN , Local_u8BIT);
	
}                                     