#include <stdint.h>
#include "stm32f407xx.h"


int main(void){
	//In the datasheet you will see ADC outputs
	ADC_TypeDef* pADC;
	//All clock control
	RCC_TypeDef* pRCC;
	//Connected to AHB1
	GPIO_TypeDef* pGPIO;
	
	//Get the base addresses
	pGPIO = GPIOA;
	pRCC = RCC;
	pADC = ADC1;
	
	//Enable  clock.
	pRCC->APB2ENR |= (1 << 8);
	pRCC->AHB1ENR |= (1 << 0);	
	
	//Set values.
	pGPIO->IDR = 0x11;
	pADC->CR1 = 0x55;
	return 0;
}