#include <usart.h>

void USARTx_Init(USART_TypeDef* USARTx, USART_ConfigTypeDef* USARTx_Config)
{
    /* Calculating and setting the Baud Rate */
    uint16_t uartDiv = 8000000/(USARTx_Config->BaudRate);
    USARTx->BRR = (((uartDiv/16) << 4) | (uartDiv%16));

    /* Enable the USART peripheral */
    USARTx->CR1 |= USART_CR1_UE;

    /* Enable the transmitter */
    USARTx->CR1 |= USART_CR1_TE;

    /* Enable the reciever */
    USARTx->CR1 |= USART_CR1_RE;

    /* Enable reciever interrupt */
    USARTx->CR1 |= USART_CR1_RXNEIE;

}

void USART_Echo(USART_TypeDef* USARTx)
{
    char* rxb = "\0";

    while (!(USARTx->SR & USART_SR_RXNE));
    rxb = USARTx->DR;
    
    while (!(USARTx->SR & USART_SR_TXE));
    USARTx->DR = rxb;
    
}

void USART3_IRQHandler(void) 
{
    char* rxb = "\0";

    // 'Receive register not empty' interrupt.
    if (USART3->SR & USART_SR_RXNE) 
    {
        /* Copy new data into the buffer */
        rxb = (USART3->DR);
    }
    
    while (!(USART3->SR & USART_SR_TXE));
    
    /* Transmit back the recieved data */
    USART3->DR = rxb;
    
}