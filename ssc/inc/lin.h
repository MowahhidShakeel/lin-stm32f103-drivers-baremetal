void LINEnable(USART_TypeDef* USARTx);
void LINTransmitData();
uint8_t CalculateChecksum(uint8_t PID, uint8_t *data, int size);
