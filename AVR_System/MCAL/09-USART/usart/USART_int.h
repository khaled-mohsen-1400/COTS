
void USART_vidInit(void);
void USART_vidSendData(u8 Copy_u8Data);
u8 USART_u8RecieveData(void);
void USART_vidSetCallBackRecieve(void (*ptr) (void));
void USART_vidSetCallBackSend(void (*ptr) (void));
