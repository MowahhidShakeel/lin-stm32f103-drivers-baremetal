#include <timer.h>
#include <gpio.h>
#include <rcc.h>

void TIMx_Init(TIM_TypeDef *TIMx, TIM_ConfigTypeDef *TIM_Init)
{
    /* If ARR is enabled, enable and configure its value */
    if (TIM_Init->autoReloadPreload == TIM_CR1_ARR_ENABLE)
    {
        TIMx->CR1 |= TIM_CR1_ARR_ENABLE;
        TIMx->ARR = TIM_Init->period;
    }
    
    /* Set the prescaler value */
    TIMx->PSC = TIM_Init->preScaler;

    /* Set the clock division */
    TIMx->CR1 |= TIM_Init->clockDivision;

    /* Set the direction of the counter */
    TIMx->CR1 |= TIM_Init->direction;

    /* Enable update */
    TIMx->CR1 |= TIM_CR1_UDIS_ENABLE;
    
    TIMx->CR1 |= TIM_CR1_CE;

    // Waiting for register changes
	while (!(TIMx->SR & (1<<0)));

}

void TIMx_Stop(TIM_TypeDef *TIMx)
{
  /* Make sure the counter is disabled */
  TIMx->CR1 &= ~(TIM_CR1_CE);

  /* Reset the peripheral */
  if (TIMx == TIM1)
  {
    RCC->APB1RSTR |= RCC_APB2RSTR_TIM1_RST;
  }
  else if (TIMx == TIM2)
  {
    RCC->APB2RSTR |= RCC_APB1RSTR_TIM2_RST;
  }
  else if (TIMx == TIM3)
  {
    RCC->APB2RSTR |= RCC_APB1RSTR_TIM3_RST;
  }
  else if (TIMx == TIM4)
  {
    RCC->APB2RSTR |= RCC_APB1RSTR_TIM4_RST;
  }

  /* Clear the "pending update" flag */
  TIMx->SR &= ~(TIM_SR_UIF);
}

void TIMx_Start(TIM_TypeDef *TIMx)
{
  /* Enable hardware interrupt*/
  TIMx->DIER |= TIM_DIER_UIE_ENABLE;

  /* Enable the timer */
  TIMx->CR1 |= TIM_CR1_CE;
  
}

void TIMx_Delay_ms(TIM_TypeDef *TIMx)
{
    /* Reset the timer */
    TIMx->CNT = (0x0000);
    
    /* Wait until timer value doesn't overflow */
    while (!(TIMx->SR&(1<<0)));

    TIMx->SR &= ~(uint32_t)(1<<0);
}

void TIM1_IRQHandler(void) {
  // Handle a timer 'update' interrupt event
  if (TIM1->SR & TIM_SR_UIF) {
    TIM1->SR &= ~(TIM_SR_UIF);
    // Toggle the LED output pin.
    GPIOB->ODR ^= (1 << 8);
  }
}

void TIM2_IRQHandler(void) 
{
  // Handle a timer 'update' interrupt event
  if (TIM2->SR & TIM_SR_UIF) {
    TIM2->SR &= ~(TIM_SR_UIF);
    // Toggle the LED output pin.
    GPIOA->ODR ^= (1 << 8);
  }
}

void TIM3_IRQHandler(void) {
  // Handle a timer 'update' interrupt event
  if (TIM3->SR & TIM_SR_UIF) {
    TIM3->SR &= ~(TIM_SR_UIF);
    // Toggle the LED output pin.
    GPIOA->ODR ^= (1 << 8);
  }
}

void TIM4_IRQHandler(void) {
  // Handle a timer 'update' interrupt event
  if (TIM4->SR & TIM_SR_UIF) {
    TIM4->SR &= ~(TIM_SR_UIF);
    // Toggle the LED output pin.
    GPIOA->ODR ^= (1 << 8);
  }
}