#include "stm32f4xx.h"
#include "RCC.h"


/*void LED_config(){
	
 RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk;
 GPIOD->MODER |= (2U<<GPIO_MODER_MODE15_Pos|2U<<GPIO_MODER_MODE14_Pos|2U<<GPIO_MODER_MODE13_Pos|2U<<GPIO_MODER_MODE12_Pos);//alternate mode
 //GPIOD->OSPEEDR|= (3U<< GPIO_OSPEEDR_OSPEED15_Pos|3U<<GPIO_OSPEEDR_OSPEED14_Pos|3U<<GPIO_OSPEEDR_OSPEED13_Pos|3U<<GPIO_OSPEEDR_OSPEED12_Pos);
 
		GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL15_Pos);
	  GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL14_Pos);
	  GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL13_Pos);
		GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL12_Pos);
}


void PWMConf(){

 RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
  TIM4->CR1 &= ~TIM_CR1_DIR; //upcounter mode
	TIM4->PSC = 24999;
	TIM4->ARR = 1000-1;
	
	//Setting the 4 channels
	TIM4->CCER |= TIM_CCER_CC1E_Msk;
	TIM4->CCER |= TIM_CCER_CC2E_Msk;
	TIM4->CCER |= TIM_CCER_CC3E_Msk;
  TIM4->CCER |= TIM_CCER_CC4E_Msk;
	
	// setting output compare mode on 4 channels
	TIM4->CCMR1 |= (6U<<TIM_CCMR1_OC1M_Pos);
	TIM4->CCMR1 |= (6U<<TIM_CCMR1_OC2M_Pos);
	TIM4->CCMR2 |= (6U<<TIM_CCMR2_OC3M_Pos);
  TIM4->CCMR2 |= (6U<<TIM_CCMR2_OC4M_Pos);
	
	TIM4->CCR1=250;//25% duty cycle on channel 1 green  = PD12
	TIM4->CCR2=500;//50% duty cycle on channel 2 orange = PD13
  TIM4->CCR3=750;//75% duty cycle on channel 3  red   = PD14
	TIM4->CCR4=950;//100% duty cycle on channel 4 blue  = PD15
	TIM4->CR1 |= TIM_CR1_CEN;//enable the timer
 
}

*/

  int main(){
		
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN_Msk; // Enable pin D
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN_Msk;// Enable the timer
 
    GPIOD->MODER |= (2U<<GPIO_MODER_MODE15_Pos); //Set the alternate mode to pins
    GPIOD->MODER |= (2U<<GPIO_MODER_MODE14_Pos);
    GPIOD->MODER |= (2U<<GPIO_MODER_MODE13_Pos);
 
    GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL15_Pos);
    GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL14_Pos);
    GPIOD->AFR[1] |=(2U<< GPIO_AFRH_AFSEL13_Pos);
 
    TIM4->CR1 &= ~TIM_CR1_DIR;
    TIM4->PSC = 24999;
    TIM4->ARR = 999;
 
    Channel Setting
    TIM4->CCER |= TIM_CCER_CC1E_Msk;
    TIM4->CCER |= TIM_CCER_CC2E_Msk;
    TIM4->CCER |= TIM_CCER_CC3E_Msk;
    TIM4->CCER |= TIM_CCER_CC4E_Msk;
 
    TIM4->CCMR1 |= (6U<<TIM_CCMR1_OC1M_Pos);
    TIM4->CCMR1 |= (6U<<TIM_CCMR1_OC2M_Pos);
    TIM4->CCMR2 |= (6U<<TIM_CCMR2_OC3M_Pos);
    TIM4->CCMR2 |= (6U<<TIM_CCMR2_OC4M_Pos);
 
 
    TIM4->CCR2=250;
    TIM4->CCR3=500;
    TIM4->CCR4=750;
 
    TIM4->CR1 |= TIM_CR1_CEN;
		
	//	LED_config();
	//	PWMConf();

}

