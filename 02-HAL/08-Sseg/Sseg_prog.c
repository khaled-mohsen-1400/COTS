#include"SSEG_int.h"
#include"SSEG_config.h"
#include"SSEG_priv.h"

void HSSEG_voidInit(void)
{
	#if HSSEG_u8PORT == PORTA
	MDIO_voidSetPortDirection(MDIO_PORTA , MDIO_OUTPUT);
	#elif HSSEG_u8PORT == PORTB
	
	#elif HSSEG_u8PORT == PORTC
	
	#elif HSSEG_u8PORT == PORTD
	
	#endif
	
}