#ifndef DEFINITIONS_H 
#define DEFINITIONS_H 

#include <stdint.h>
#include <gpio.h>
#include <timer.h>
#include <rcc.h>
#include <peripheral.h>
#include <usart.h>
#include <lin.h>
#endif

int main(void) 
{
    GPIO_Config GPIO_InitStruct = {0};
    TIM_ConfigTypeDef TIM_InitStruct = {0};
    USART_ConfigTypeDef USART_InitStruct = {0};

    GPIOA_CLK_ENABLE();
    GPIOB_CLK_ENABLE();
    SysClockConfig();
    TIM3_ENABLE();
    
    GPIO_USART3_Init();

    USART3_ENABLE();
    LINEnable(USART3);
    
    // NVIC_EnableIRQ(TIM3_IRQn);
    NVIC_EnableIRQ(USART3_IRQn);
    
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    
    TIM_InitStruct.clockDivision = TIM_CR1_CLK_DIV1;
    TIM_InitStruct.direction = TIM_CR1_DIR_UP;
    TIM_InitStruct.autoReloadPreload = TIM_CR1_ARR_ENABLE;
    TIM_InitStruct.preScaler = 7;
    TIM_InitStruct.period = 999;
    TIMx_Init(TIM3, &TIM_InitStruct);

    USART_InitStruct.BaudRate = 20000;
    USARTx_Init(USART3, &USART_InitStruct);

    while (1)
    {
        for (int i=0; i<100; i++)
        {
            TIMx_Delay_ms(TIM3);
        }
        LINTransmitData();
        
    }
    return 0;
}
