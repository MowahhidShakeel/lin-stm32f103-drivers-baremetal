#include <stdint.h>

/* RCC_APB2ENR Ports Clk configuration */
#define RCC_APB2ENR_IOPA_CLK_EN             (0x0004UL)  /* Port A Clk enable */
#define RCC_APB2ENR_IOPB_CLK_EN             (0x0008UL)  /* Port B Clk enable */
#define RCC_APB2ENR_IOPC_CLK_EN             (0x0010UL)  /* Port C Clk enable */
#define RCC_APB2ENR_IOPD_CLK_EN             (0x0020UL)  /* Port D Clk enable */
#define RCC_APB2ENR_IOPE_CLK_EN             (0x0040UL)  /* Port E Clk enable */

#define RCC_APB2ENR_IOPA_CLK_DIS            (0xFFFBUL)  /* Port A Clk disable */
#define RCC_APB2ENR_IOPB_CLK_DIS            (0xFFF7UL)  /* Port B Clk disable */
#define RCC_APB2ENR_IOPC_CLK_DIS            (0xFFEFUL)  /* Port C Clk disable */
#define RCC_APB2ENR_IOPD_CLK_DIS            (0xFFDFUL)  /* Port D Clk disable */
#define RCC_APB2ENR_IOPE_CLK_DIS            (0xFFBFUL)  /* Port E Clk disable */

#define RCC_APB2RSTR_TIM1_RST               (0x00000800u)   /* Timer 1 reset */
#define RCC_APB1RSTR_TIM2_RST               (0x00000001u)   /* Timer 2 reset */
#define RCC_APB1RSTR_TIM3_RST               (0x00000002u)   /* Timer 3 reset */
#define RCC_APB1RSTR_TIM4_RST               (0x00000004u)   /* Timer 4 reset */

/* Osciallation type configuration */
#define RCC_OSC_TYPE_NONE                   (0x00000000u)   /* No osciallatory clock selected */
#define RCC_OSC_TYPE_HSE                    (0x00000001u)   /* HSE Clock oscillation selected */
#define RCC_OSC_TYPE_HSI                    (0x00000002u)   /* HSI Clock oscillation selected */
#define RCC_OSC_TYPE_LSE                    (0x00000004u)   /* LSE Clock oscillation selected */
#define RCC_OSC_TYPE_LSI                    (0x00000008u)   /* LSI Clock oscillation selected */

/* HSI Configuration */
#define RCC_CR_HSI_OFF                      (0x00000000u)
#define RCC_CR_HSI_ON                       (0x00000001u)

#define RCC_CR_HSI_READY                    (0x00000002u)
#define RCC_CR_HSI_NOT_READY                (0x00000000u)

#define RCC_HSI_CALIBRATION                 (0x10u)         /* Default HSI calibration */

/* PLL Configuration */
#define RCC_PLL_STATE_NONE                  (0x00000000u)
#define RCC_PLL_STATE_READY                 (0x00000001u)
#define RCC_PLL_STATE_NOT_READY             (0x00000002u)

#define RCC_PLL_SRC_HSI_DIV2                (0xFFFEFFFFu)
#define RCC_PLL_SRC_HSE                     (0x00010000u)

#define RCC_PLL_MUL_2                       (0x00000000u)
#define RCC_PLL_MUL_3                       (0x00040000u)
#define RCC_PLL_MUL_4                       (0x00080000u)
#define RCC_PLL_MUL_5                       (0x000C0000u)
#define RCC_PLL_MUL_6                       (0x00100000u)
#define RCC_PLL_MUL_7                       (0x00140000u)
#define RCC_PLL_MUL_8                       (0x00180000u)
#define RCC_PLL_MUL_9                       (0x001C0000u)
#define RCC_PLL_MUL_10                      (0x00200000u)
#define RCC_PLL_MUL_11                      (0x00240000u)
#define RCC_PLL_MUL_12                      (0x00280000u)
#define RCC_PLL_MUL_13                      (0x002C0000u)
#define RCC_PLL_MUL_14                      (0x00300000u)
#define RCC_PLL_MUL_15                      (0x00340000u)
#define RCC_PLL_MUL_16                      (0x00380000u)

#define RCC_APB2ENR_TIM1_ENABLE             (0x00000800u)
#define RCC_APB1ENR_TIM2_ENABLE             (0x00000001u)
#define RCC_APB1ENR_TIM3_ENABLE             (0x00000002u)
#define RCC_APB1ENR_TIM4_ENABLE             (0x00000004u)
#define RCC_APB1ENR_TIM5_ENABLE             (0x00000008u)
#define RCC_APB1ENR_TIM6_ENABLE             (0x0000000Cu)
#define RCC_APB1ENR_TIM7_ENABLE             (0x00000010u)
#define RCC_APB1ENR_TIM12_ENABLE            (0x00000014u)
#define RCC_APB1ENR_TIM13_ENABLE            (0x00000018u)

#define RCC_APB2ENR_USART1_ENABLE           (0x00004000u)
#define RCC_APB1ENR_USART2_ENABLE           (0x00020000u)
#define RCC_APB1ENR_USART3_ENABLE           (0x00040000u)
#define RCC_APB1ENR_USART4_ENABLE           (0x00080000u)
#define RCC_APB1ENR_USART5_ENABLE           (0x00100000u)

#define RCC_APB2ENR_AFIO_ENABLE             (0x00000001u)   /* Alternate function clock enable */
#define FLASH_ACR                           (0x40022000u)

#define FLASH_ACR_PRFTBE                    (0x00000010u)
#define FLASH_ACR_LATENCY_0                 (0x00000001u)   
#define FLASH_ACR_LATENCY_1                 (0x00000002u) 
#define FLASH_ACR_LATENCY_2                 (0x00000004u)   
#define RCC                                 ((RCC_TypeDef *)0x40021000UL)    /* Memory space for RCC */

typedef struct
{
    uint32_t PLLState;           /* State of the PLL     */
    uint32_t PLLSRC;             /* PLL clock source     */
    uint32_t PLLMUl;             /* PLL clock multiplier */ 

} PLL_InitTypeDef;

typedef struct
{
    uint32_t OscillatorType;    /* The osciallator to be configured */
    uint32_t HSEState;          /* HSE state                        */ 
    uint32_t HSEPrediv;          /* The prediv factor for HSE        */
    uint32_t LSEState;          /* LSE state                        */
    uint32_t HSIState;          /* HSI state                        */
    uint32_t HSICalibration;     /* The calibrationvalue for HSI     */
    uint32_t LSIState;          /* LSI state                        */
    PLL_InitTypeDef PLL;        /* PLL typedef structure parameters */

} RCC_OscInitTypeDef;

typedef struct
{
  uint32_t CR;
  uint32_t CFGR;
  uint32_t CIR;
  uint32_t APB2RSTR;
  uint32_t APB1RSTR;
  uint32_t AHBENR;
  uint32_t APB2ENR;
  uint32_t APB1ENR;
  uint32_t BDCR;
  uint32_t CSR;

} RCC_TypeDef;

void GPIOA_CLK_ENABLE();
void GPIOB_CLK_ENABLE();
void GPIOC_CLK_ENABLE();
void GPIOD_CLK_ENABLE();
void GPIOA_CLK_DISABLE();
void GPIOB_CLK_DISABLE();
void GPIOC_CLK_DISABLE();
void GPIOD_CLK_DISABLE();

void TIM1_ENABLE();
void TIM2_ENABLE();
void TIM3_ENABLE();
void TIM4_ENABLE();

void USART1_ENABLE();
void USART2_ENABLE();
void USART3_ENABLE();
void USART4_ENABLE();
void USART5_ENABLE();

void SysClockConfig();