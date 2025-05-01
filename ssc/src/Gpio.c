#include <gpio.h>
#include <rcc.h>

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState != GPIO_PIN_RESET)
    {
        GPIOx->BSRR = GPIO_Pin;
    }
    else
    {
        GPIOx->BSRR = (uint32_t)GPIO_Pin << 16u;
    }
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    uint32_t odr = GPIOx->ODR;   /* Get the current ODR reg value */

    /* If bit is 1 at pin number */
    if ((odr & GPIO_Pin) == GPIO_Pin)
    {   
        GPIOx->BRR |= GPIO_Pin;
    }
    /* Else bit is 0 at pin number */
    else
    {
        GPIOx->BSRR |= GPIO_Pin;
    }
}

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Config *GPIO_Init)
{
    uint32_t position = 0x00u;      /* Keep track of the while loop and iterate over all pin positions */
    uint32_t config = 0x00u;        /* Store the config / mode settings */
    uint32_t ioPosition = 0;        /* Iterate over individual bit */
    uint32_t ioCurrent = 0;         /* To check if ioPosition and position are equal at a certain bit */

    uint32_t *configRegister;       /* Store the address of CRL or CRH register based on pin number */
    uint32_t registerOffset;        /* offset used during computation of CNF and MODE bits placement inside CRL or CRH register */
    uint32_t clearMask;             /* Clear all other bits of configRegister */  

    while(((GPIO_Init->Pin) >> position) != 0x00u)
    {
        ioPosition = (0x01uL << position);

        /* If the Pin is 1 at ioPosition, set ioCurrent*/
        ioCurrent = (GPIO_Init->Pin) & ioPosition;

        if (ioCurrent == ioPosition)
        {
            /* Based on the required mode, filling config variable with MODEy[1:0] and CNFy[3:2] corresponding bits */
            switch (GPIO_Init->Mode)
            {
                case GPIO_MODE_OUTPUT_PP:
                config = GPIO_Init->Speed + GPIO_CR_CNF_GP_OUTPUT_PP;
                break;

                /* If we are configuring the pin in OUTPUT open-drain mode */
                case GPIO_MODE_OUTPUT_OD:
                config = GPIO_Init->Speed + GPIO_CR_CNF_GP_OUTPUT_OD;
                break;

                /* If we are configuring the pin in ALTERNATE FUNCTION push-pull mode */
                case GPIO_MODE_AF_PP:
                config = GPIO_Init->Speed + GPIO_CR_CNF_AF_OUTPUT_PP;
                break;

                /* If we are configuring the pin in ALTERNATE FUNCTION open-drain mode */
                case GPIO_MODE_AF_OD:
                config = GPIO_Init->Speed + GPIO_CR_CNF_AF_OUTPUT_OD;
                break;

                case GPIO_MODE_INPUT:
                    if (GPIO_Init->Pull == GPIO_NOPULL)
                    {
                        config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_FLOATING;
                    }
                    else if (GPIO_Init->Pull == GPIO_PULLUP)
                    {
                        config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_PU_PD;

                        /* Set the corresponding ODR bit */
                        GPIOx->BSRR = ioPosition;
                    }
                    else /* GPIO_PULLDOWN */
                    {
                        config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_PU_PD;

                        /* Reset the corresponding ODR bit */
                        GPIOx->BRR = ioPosition;
                    }
                break;

                default:
                break;
            }
        }

        /* Choose either CRH or CRL based on GPIO pin number */
        configRegister = (ioCurrent < GPIO_PIN_8) ? &GPIOx->CRL     : &GPIOx->CRH;
        registerOffset = (ioCurrent < GPIO_PIN_8) ? (position << 2u) : ((position - 8u) << 2u);

        /* Write the value to the selected register */
        clearMask = ~((GPIO_CRL_MODE | GPIO_CRL_CNF) << registerOffset);
        *configRegister = *configRegister & clearMask;
        *configRegister = *configRegister | (config << registerOffset);

        position++;
    }
}

void GPIO_USART1_Init()
{
    GPIO_Config GPIO_InitStruct = {0};
    GPIOA_CLK_ENABLE();

    /* Setting PA9 to TX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Setting PA10 to RX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void GPIO_USART2_Init()
{
    GPIO_Config GPIO_InitStruct = {0};
    GPIOA_CLK_ENABLE();

    /* Setting PA2 to TX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Setting PA3 to RX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void GPIO_USART3_Init()
{
    GPIO_Config GPIO_InitStruct = {0};
    GPIOB_CLK_ENABLE();

    /* Setting PB10 to TX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Setting PB11 to RX mode */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

}