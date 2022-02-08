// program 
0x0f -> 0xf0
0xf0 -> 0x0f
void KeyPad_voidInit(void)
{
   MDIO_voidSetPortDir(HKeyPad_PORT , HKeyPad_DIREC);
   #if HKeyPad_WIRING == HKeyPad_INTPULL
   MDIO_voidSetPinVal(HKeyPad_C1 , HKeyPad_HIGH);
   MDIO_voidSetPinVal(HKeyPad_C2 , HKeyPad_HIGH);
   MDIO_voidSetPinVal(HKeyPad_C3 , HKeyPad_HIGH);
   MDIO_voidSetPinVal(HKeyPad_C4 , HKeyPad_HIGH);
   #if HKeyPad_WIRING == HKeyPad_EXTPULL
   #endif
}
u8 KeyPad_u8GetButton(void)
{
    u8 Local_u8_Result = '\0';
    MDIO_voidSetPinVal(HKeyPad_R1 , HKeyPad_LOW);
	MDIO_voidSetPinVal(HKeyPad_R2 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R3 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R4 , HKeyPad_HIGH);
	
	Local_u8_Result = HKeyPad_GetColmn(HKeyPad_R1);
	if(Local_u8_Result != '\0')
	return Local_u8_Result;
	
	
	   MDIO_voidSetPinVal(HKeyPad_R1 , HKeyPad_LOW);
	MDIO_voidSetPinVal(HKeyPad_R2 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R3 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R4 , HKeyPad_HIGH);
	
	Local_u8_Result = HKeyPad_GetColmn(HKeyPad_R1);
	if(Local_u8_Result != '\0')
	return Local_u8_Result;
	
	
	
	   MDIO_voidSetPinVal(HKeyPad_R1 , HKeyPad_LOW);
	MDIO_voidSetPinVal(HKeyPad_R2 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R3 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R4 , HKeyPad_HIGH);
	
	Local_u8_Result = HKeyPad_GetColmn(HKeyPad_R1);
	if(Local_u8_Result != '\0')
	return Local_u8_Result;
	
	
	   MDIO_voidSetPinVal(HKeyPad_R1 , HKeyPad_LOW);
	MDIO_voidSetPinVal(HKeyPad_R2 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R3 , HKeyPad_HIGH);
	MDIO_voidSetPinVal(HKeyPad_R4 , HKeyPad_HIGH);
	
	Local_u8_Result = HKeyPad_GetColmn(HKeyPad_R1);
	if(Local_u8_Result != '\0')
	return Local_u8_Result;
	
}


static u8 HKeyPad_GetColmn(u8 Copy_Row)
{
  switch(Copy_Row)
  {
     case HKeyPad_R1:
	 if( MDIO_u8GetPinValue(HKeyPad_C1) == 0)
	 return HKeyPad_R1C1;
	 
	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 break;
	 
	     case HKeyPad_R2:
	 if( MDIO_u8GetPinValue(HKeyPad_C1) == 0)
	 return HKeyPad_R1C1;
	 
	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 break;
	 
	 
	     case HKeyPad_R3:
	 if( MDIO_u8GetPinValue(HKeyPad_C1) == 0)
	 return HKeyPad_R1C1;
	 
	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 break;
	 
	     case HKeyPad_R4:
	 if( MDIO_u8GetPinValue(HKeyPad_C1) == 0)
	 return HKeyPad_R1C1;
	 
	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 
	 	 else if( MDIO_u8GetPinValue(HKeyPad_C2) == 0)
	 return HKeyPad_R1C2;
	 break;
	 
  }
}