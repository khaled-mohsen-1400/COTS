/************************************************/
/* Title       : EXTI Main file                 */
/* Author      : Khaled Mohsen                  */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "GIE_int.h"

void func(void) //ISR -> non callable
{
  static u8 flag = 0;

  if(flag == 0)
  {
   DIO_vid_SetPinValue(DIO_u8_PIN_0 , DIO_u8_HIGH);
   flag = 1;
  }
  else
  {
   DIO_vid_SetPinValue(DIO_u8_PIN_0 , DIO_u8_LOW);
   flag = 0;
  }

}


int main(void)
{
   DIO_vid_Init();
   DIO_vid_SetPinValue(DIO_u8_PIN_26 , DIO_u8_HIGH);
   EXTI_voidInit();
   EXTI_voidSetCallBack(func);
   EXTI_voidEnable(); //PIE on
   GIE_voidEnable();  // GIE on

	while(1)
	{
        
	}
	EXTI_voidDisable();
	return 0 ;
}
