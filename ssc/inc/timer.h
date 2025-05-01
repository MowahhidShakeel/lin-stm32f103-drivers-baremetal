#include <stdint.h>

#define TIM1                    ((TIM_TypeDef*)0x40012C00u)
#define TIM2                    ((TIM_TypeDef*)0x40000000u)
#define TIM3                    ((TIM_TypeDef*)0x40000400u)
#define TIM4                    ((TIM_TypeDef*)0x40000800u)

#define TIM_CR1_ARR_DISABLE     (0x00000000u)
#define TIM_CR1_ARR_ENABLE      (0x00000080u)

#define TIM_CR1_CLK_DIV1        (0x00000000u)
#define TIM_CR1_CLK_DIV2        (0x00000100u)
#define TIM_CR1_CLK_DIV4        (0x00000200u)

#define TIM_CR1_UDIS_DISABLE    (0x00000002u)
#define TIM_CR1_UDIS_ENABLE     (0x00000000u)

#define TIM_CR1_DIR_UP          (0x00000000u)
#define TIM_CR1_DIR_DOWN        (0x00000010u)

#define TIM_CR1_CE  (0x00000001u)

#define TIM_SF_UIF_UPDATE       (0x00000001u)

#define TIM_DIER_UIE_ENABLE     (0x0001u)   /* Interrupt enable      */
#define TIM_EGR_UG_ENABLE       (0x0001u)   /* Update generation     */
#define TIM_SR_UIF              (0x0001u)   /* Update interrupt flag */

typedef struct {

    uint32_t CR1;       /* Control register 1               */
    uint32_t CR2;       /* Control register 2               */
    uint32_t SMCR;      /* Slave mode control register      */
    uint32_t DIER;      /* DMA Interrupt enable register    */
    uint32_t SR;        /* Status register                  */
    uint32_t EGR;       /* Event generation register        */
    uint32_t CCMR1;     /* Capture compare mode register    */
    uint32_t CCMR2;     /* Capture compare mod register 2   */
    uint32_t CCER;      /* Capture compare enable register  */
    uint32_t CNT;       /* Counter register                 */
    uint32_t PSC;       /* Prescaler register               */
    uint32_t ARR;       /* Auto-reload register             */
    uint32_t RCR;       /* Repetition counter register      */
    uint32_t CCR1;      /* Capture compare register 1       */
    uint32_t CCR2;      /* Capture compare register 2       */
    uint32_t CCR3;      /* Capture compare register 3       */
    uint32_t CCR4;      /* Capture compare register 4       */
    uint32_t BDTR;      /* Break and dead-time register     */
    uint32_t DCR;       /* DMA Control register             */
    uint32_t DMAR;      /* DMA address for full transfer    */
    
} TIM_TypeDef;

typedef struct {

    uint32_t preScaler;         /* Prescaler value to divide the TIM clock  */
    uint32_t period;            /* Period value for the ARR register        */
    uint32_t clockDivision;     /* Division ration between timer clk freq and the dead-time and sampling clock.*/
    uint32_t direction;         /* Counter used as upcounter or downcounter */
    uint32_t counterEn;         /* Enable the timer counter                 */
    uint32_t autoReloadPreload; /* Enable or disable auto-reload preload    */

} TIM_ConfigTypeDef;

void TIMx_Init(TIM_TypeDef *TIMx, TIM_ConfigTypeDef *TIM_Init);
void TIMx_Start(TIM_TypeDef *TIMx);
void TIMx_Delay_ms(TIM_TypeDef *TIMx);
void TIMx_Delay(TIM_TypeDef *TIMx);
void TIMx_Stop(TIM_TypeDef *TIMx);
void TIM1_PWM_Init(TIM_TypeDef *TIMx);