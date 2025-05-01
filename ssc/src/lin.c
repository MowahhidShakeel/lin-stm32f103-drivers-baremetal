#include <usart.h>
#include <lin.h>

void LINEnable(USART_TypeDef* USARTx)
{
    /* Clear the mentioned bits */
    USARTx->CR2 &= ~(USART_CR2_CLKEN);   /* Disable the CLKEN    */
    USARTx->CR2 &= ~(USART_CR2_STOP);    /* Clear the STOP bits  */

    /* Enable the LIN mode  */
    USARTx->CR2 |= USART_CR2_LINEN;
}

uint8_t CalculateChecksum(uint8_t PID, uint8_t *data, int size)
{
	uint8_t buffer[size+2];
	uint16_t sum = 0;

    /* PID included in checksum calculation */
	buffer[0] = PID;

    /* Copy data to a buffer */
	for (int i=0; i<size; i++)
	{
		buffer[i+1] = data[i];
	}

    /* Calculate the checksum */
	for (int i=0; i<size+1; i++)
	{
		sum += buffer[i];
		if (sum>0xff)
        {
            sum = sum-0xFF;
        }
	}

    /* Invert the value */
	sum = 0xFF-sum;
	return sum;
}


void LINTransmitData()
{
    /* Frame to transmit the data */
    uint8_t TxData[20];

    /* Sync byte field */
    TxData[0] = 0x55;

    /* Protected ID field */
    TxData[1] = 0x80;

    /* Data bits */
    for (int i=0; i<8; i++)
    {
        TxData[i+2] = i;
    }

    /* Checksum field value */
    TxData[10] = CalculateChecksum(TxData[1], TxData+2, 8);

    /* Send LIN break */
    USART3->CR1 |= USART_CR1_SBK;

    /* Transmit the buffer over USART */
    for (int i=0; i<=10; i++)
    {
        while (!(USART3->SR & USART_SR_TXE));
        
        /* Transmit back the recieved data */
        USART3->DR = TxData[i];
    }
}