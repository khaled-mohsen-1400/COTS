void SPI_vidInit(void)
{
	#if SPI_u8_DATA_ORDER == SPI_u8_LSB
	  SET_BIT(SPCR , DORD);
	#elif SPI_u8_DATA_ORDER == SPI_u8_MSB
	  CLEAR_BIT(SPCR , DORD);
	#endif
	
	
	#if SPI_u8_M_S_MODE == SPI_u8_MASTER
	  SET_BIT(SPCR , DORD);
	#elif SPI_u8_M_S_MODE == SPI_u8_SLAVE
	  CLEAR_BIT(SPCR , DORD);
	#endif
	
	CLEAR_BIT(SPCR , CPOL);
	CLEAR_BIT(SPCR , CPHA);
	
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPSR , SPI2X);
	
	SET_BIT(SPCR , SPE);
	
}
void SPI_vidEnable(void)
{
	SET_BIT(SPCR , SPE);
}
void SPI_vidDisable(void)
{
	CLEAR_BIT(SPCR , SPE);
}

void SPI_vidSend(u8 Copy_Data)
{
	SPDR = Copy_Data;	
}

u8 SPI_u8Recieve(void) //slave use this in main
{
	return SPDR;
}

u8 SPI_u8Transfer(u8 Copy_Data) // master wants slave data 
{
	SPDR = Copy_Data;	
    while(GET_BIT(SPSR , SPIF) == 0);	// data still transfer
	return SPDR;
}
void SPI_vidSetCallBack(void (*ptr) (void));