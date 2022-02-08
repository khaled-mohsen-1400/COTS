void USART_vidInit(void)
{
	/* enable RX TX */
	SET_BIT(UCSRB , RXEN);
	SET_BIT(UCSRB , TXEN);
	
	/* define fram data size */
	CLEAR_BIT(UCSRB , UCSZ2);
	SET_BIT(UCSRC , UCSZ1);
	SET_BIT(UCSRC , UCSZ0);
	
	/* asynchrones */
	CLEAR_BIT(UCSRC ,UMSEL);
	
	/*no parety*/
	CLEAR_BIT(UCSRC ,UPM0);
	CLEAR_BIT(UCSRC ,UPM1);
	
	/* 1 stop bit */
	CLEAR_BIT(UCSRC ,USBS);
	
	/*no polarity*/
	CLEAR_BIT(UCSRC ,UCPOL);
	
	/*baud rate*/
	UBRRH = 0; // I want to write on UBRRH
	UBRRL = 51;
}

void USART_vidSendData(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,TXC) == 0);
	UDR = Copy_u8Data;
}
u8 USART_u8RecieveData(void)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
}
void USART_vidSetCallBackRecieve(void (*ptr) (void));
void USART_vidSetCallBackSend(void (*ptr) (void));