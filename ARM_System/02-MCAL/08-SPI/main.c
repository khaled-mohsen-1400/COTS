
int main(void)
{

  u32 Arr1[1000] = {0};
  u32 Arr2[1000];
  
  u32 Arr3[1000] = {0};
  u32 Arr4[1000];
  
  /* rcc init and DMA AHP 0 */
  
  /* DMA init */
  
  /* NVIC init enable DMA 11 */
  
  HDMA_voidChannelStart(Arr1 , Arr2 , 1000);
  
  for(u16 i = 0; i < 1000; i++)
  {
	Arr4[i] = Arr3[i];  
  }
  
  while(1)
  {
  
  
  }


return 0;

}

void DMA1_Channel1_IQHandler(void)
{
	/* read number of elements */
	
	/* clear  GIF */
	DMA -> IFCR = 1<< 0; 
	/* clear  TC */
	DMA -> IFCR = 1<< 1;
}