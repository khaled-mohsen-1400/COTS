

int main (void)
{
	
	/* initialization */
	RCC_voidSystemClock();
	RCC_voidClockEnable(APB2 , 2);
	
	void LED1(void);
	void LED2(void);
	void LED3(void);
	
	GPIO_voidInit();
	
	SOS_voidCreateTask(0 , 1000 , LED1);
	
	SOS_voidCreateTask(1 , 2000 , LED2);
	
	SOS_voidCreateTask(2 , 3000 , LED3);
	while(1)
	{
		
	}
	
	return 0;
}

void LED1(void)
{
	TOG_BIT();
}