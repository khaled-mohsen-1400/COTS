/*****************************************/
/* Author  : Khaled Mohsen               */
/* Date    : 27 August 2020              */
/* Version : V01                         */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "SSegment_int.h"
#include "SSegment_config.h"
#include "SSegment_priv.h"


//#define START_VALUE 	0
//#define END_VALUE		8
#define ARR_SIZE		10

static u8 Ssegment_u8Array[ARR_SIZE] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };
void Ssegment_void_WriteNum(u8 Copy_u8_SsegmentNum , u8 Copy_u8_Num)
{
	//u8 Local_u8_LoopIndex ;
#ifdef FIRST_SEGMENT

	if(Copy_u8_SsegmentNum == SSEGMENT_ONE)
	{
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_0) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_1) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_B , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_B , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_2) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_C , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_C , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_3) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_D , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_D , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_4) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_E , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_E , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_5) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_F , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_F , DIO_u8_LOW);
		}
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_6) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_G , DIO_u8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_G , DIO_u8_LOW);
		}

		/*
		for(Local_u8_LoopIndex = START_VALUE ; Local_u8_LoopIndex < END_VALUE ; Local_u8_LoopIndex++)
		{
			if(GET_BIT(Ssegment_u8Array[Copy_u8_Num] , Local_u8_LoopIndex))
			{
				DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A+Local_u8_LoopIndex , DIO_u8_HIGH);
			}
			else
			{
				DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A+Local_u8_LoopIndex , DIO_u8_LOW);
			}
		}
		 */

	}
#endif

#ifdef SECOND_SEGMENT
	if(Copy_u8_SsegmentNum == SSEGMENT_TWO)
	{
		if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_0) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_1) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_B , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_B , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_2) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_C , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_C , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_3) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_D , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_D , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_4) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_E , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_E , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_5) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_F , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_F , DIO_u8_LOW);
				}
				if( GET_BIT(Ssegment_u8Array[Copy_u8_Num] , BIT_6) )
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_G , DIO_u8_HIGH);
				}
				else
				{
					DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_G , DIO_u8_LOW);
				}

		/*
		for(Local_u8_LoopIndex = START_VALUE ; Local_u8_LoopIndex < END_VALUE ; Local_u8_LoopIndex++)
		{
			if(GET_BIT(Ssegment_u8Array[Copy_u8_Num] , Local_u8_LoopIndex))
			{
				DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A+Local_u8_LoopIndex , DIO_u8_HIGH);
			}
			else
			{
				DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A+Local_u8_LoopIndex , DIO_u8_LOW);
			}
		}
		*/

	}
#endif


} // end of function

void Ssegment_void_Clear(u8 Copy_u8_SsegmentNum)
{
	u8 Local_u8_LoopIndex;
	if(Copy_u8_SsegmentNum == SSEGMENT_ONE)
	{
	  for(Local_u8_LoopIndex = 0; Local_u8_LoopIndex < 6; Local_u8_LoopIndex++)
	  DIO_vid_SetPinValue(Local_u8_LoopIndex , DIO_u8_LOW);
	}
	else
	{
	  for(Local_u8_LoopIndex = 8; Local_u8_LoopIndex < 14; Local_u8_LoopIndex++)
	  DIO_vid_SetPinValue(Local_u8_LoopIndex , DIO_u8_LOW);
	}

}
