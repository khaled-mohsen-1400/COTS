
void SPI_vidInit(void);
void SPI_vidIntEnable(void);
void SPI_vidIntDisable(void);
void SPI_vidSend(u8 Copy_Data);
u8 SPI_u8Recieve(void);
void SPI_vidSetCallBack(void (*ptr) (void));
