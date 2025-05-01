#include <stdint.h>

#define USART1              ((USART_TypeDef*)0x40013800u)       /* Memory address for USART1 */
#define USART2              ((USART_TypeDef*)0x40004400u)       /* Memory address for USART2 */
#define USART3              ((USART_TypeDef*)0x40004800u)       /* Memory address for USART3 */

#define USART_CR1_UE        (0x00002000u) /* USART enable       */
#define USART_CR1_TE        (0x00000008u) /* Transmitter enable */
#define USART_CR1_RE        (0x00000004u) /* Reciever enable    */
#define USART_CR1_SBK       (0x00000001u) /* Send break char    */
#define USART_CR1_RXNEIE    (0x00000020u) /* RXNE interrupt enable */

#define USART_CR2_LINEN     (0x00004000u)   /* Enable LIN mode      */
#define USART_CR2_STOP      (0x00003000u)   /* 1.5 Stop bit         */
#define USART_CR2_CLKEN     (0x00000800u)   /* Enable the CK pin    */

#define USART_SR_RXNE       (0x00000020u) /* Read data register not empty */
#define USART_SR_TXE        (0x00000080u) /* Transmit data register empty */


typedef struct 
{   
    uint32_t SR;        /* Status Register      */
    uint32_t DR;        /* Data Register        */
    uint32_t BRR;       /* Baud Rate Register   */
    uint32_t CR1;       /* Control Register 1   */
    uint32_t CR2;       /* Control Register 2   */
    uint32_t CR3;       /* Control Register 3   */
    uint32_t GTPR;      /* Guard time and prescaler register */

} USART_TypeDef;

typedef struct 
{
    uint32_t BaudRate;      /* Sets the UART communication baud rate                 */
    uint32_t WordLength;    /* The data bits transmitted in a frame                  */
    uint32_t StopBits;      /* Specify the number of stop bits transmitted           */
    uint32_t Parity;        /* Specify the parity mode                               */
    uint32_t Mode;          /* Specify transmit or recieve mode                      */
    uint32_t HwFlowCtrl;    /* Enable or disable hardware flow control               */
    uint32_t OverSampling;  /* Specify whether over sampling 8 is enable or disabled */

} USART_ConfigTypeDef;

void USARTx_Init(USART_TypeDef* USARTx, USART_ConfigTypeDef* USARTx_Config);
void USART_Echo(USART_TypeDef* USARTx);