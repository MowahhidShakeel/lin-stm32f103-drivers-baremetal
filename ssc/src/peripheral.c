#include <peripheral.h>

/* Enables device specific interrupt number */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if (((int32_t)(IRQn)) >= 0 & ((int32_t)(IRQn) <= 31))
  {
    NVIC->ISER[0] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
  else if ((int32_t)(IRQn) > 31)
  {
    NVIC->ISER[1] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}