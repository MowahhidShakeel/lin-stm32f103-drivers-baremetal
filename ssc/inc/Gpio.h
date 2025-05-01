#include <stdint.h>

#define GPIO_NOPULL                         (0x00000000u)   /* No Pull-up or Pull-down activation  */
#define GPIO_PULLUP                         (0x00000001u)   /* Pull-up activation                  */
#define GPIO_PULLDOWN                       (0x00000002u)   /* Pull-down activation                */

#define GPIO_CRL_MODE                       (0x00000003UL)   
#define GPIO_CRL_CNF                        (0x0000000CUL)     

#define GPIO_PIN_0                          (0x0001UL)  /* GPIO Pin 0  */
#define GPIO_PIN_1                          (0x0002UL)  /* GPIO Pin 1  */
#define GPIO_PIN_2                          (0x0004UL)  /* GPIO Pin 2  */
#define GPIO_PIN_3                          (0x0008UL)  /* GPIO Pin 3  */
#define GPIO_PIN_4                          (0x0010UL)  /* GPIO Pin 4  */
#define GPIO_PIN_5                          (0x0020UL)  /* GPIO Pin 5  */
#define GPIO_PIN_6                          (0x0040UL)  /* GPIO Pin 6  */
#define GPIO_PIN_7                          (0x0080UL)  /* GPIO Pin 7  */
#define GPIO_PIN_8                          (0x0100UL)  /* GPIO Pin 8  */
#define GPIO_PIN_9                          (0x0200UL)  /* GPIO Pin 9  */
#define GPIO_PIN_10                         (0x0400UL)  /* GPIO Pin 10 */
#define GPIO_PIN_11                         (0x0800UL)  /* GPIO Pin 11 */
#define GPIO_PIN_12                         (0x1000UL)  /* GPIO Pin 12 */
#define GPIO_PIN_13                         (0x2000UL)  /* GPIO Pin 13 */
#define GPIO_PIN_14                         (0x4000UL)  /* GPIO Pin 14 */
#define GPIO_PIN_15                         (0x8000UL)  /* GPIO Pin 15 */
#define GPIO_PIN_ALL                        (0xFFFFUL)  /* All GPIO Pins selected */

#define  GPIO_MODE_INPUT                    (0x00000000u)       /* Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP                (0x00000001u)       /* Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD                (0x00000011u)       /* Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP                    (0x00000002u)       /* Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD                    (0x00000012u)       /* Alternate Function Open Drain Mode    */
#define  GPIO_MODE_AF_INPUT                 (GPIO_MODE_INPUT)   /* Alternate Function Input Mode         */

#define  GPIO_CR_MODE_INPUT                 ((uint32_t)0x00000000u)
#define  GPIO_CR_CNF_ANALOG                 ((uint32_t)0x00000000u) 
#define  GPIO_CR_CNF_INPUT_FLOATING         ((uint32_t)0x00000004u) 
#define  GPIO_CR_CNF_INPUT_PU_PD            ((uint32_t)0x00000008u)
#define  GPIO_CR_CNF_GP_OUTPUT_PP           ((uint32_t)0x00000000u)
#define  GPIO_CR_CNF_GP_OUTPUT_OD           ((uint32_t)0x00000004u)
#define  GPIO_CR_CNF_AF_OUTPUT_PP           ((uint32_t)0x00000008u)
#define  GPIO_CR_CNF_AF_OUTPUT_OD           ((uint32_t)0x0000000Cu)

#define GPIO_SPEED_FREQ_LOW                 (0x2UL) /* Low speed */
#define GPIO_SPEED_FREQ_MEDIUM              (0x1UL) /* Medium speed */
#define GPIO_SPEED_FREQ_HIGH                (0x3UL) /* High speed */

#define GPIOA                               ((GPIO_TypeDef *)0x40010800UL)   /* Memory space for Port A */
#define GPIOB                               ((GPIO_TypeDef *)0x40010C00UL)   /* Memory space for Port B */
#define GPIOC                               ((GPIO_TypeDef *)0x40011000UL)   /* Memory space for Port C */
#define GPIOD                               ((GPIO_TypeDef *)0x40014000UL)   /* Memory space for Port D */
#define GPIOE                               ((GPIO_TypeDef *)0x40018000UL)   /* Memory space for Port E */


typedef struct
{
    uint32_t Pin;   // Specify the GPIO pin
    uint32_t Mode;  // Specify the operating mode
    uint32_t Pull;  // Specify the pull-up or pull-down mode
    uint32_t Speed; // Specify the speed

} GPIO_Config;

typedef struct 
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_TypeDef;

typedef enum
{
  GPIO_PIN_RESET = 0u,
  GPIO_PIN_SET
} GPIO_PinState;

void GPIOA_CLK_ENABLE();
void GPIOB_CLK_ENABLE();
void GPIOC_CLK_ENABLE();
void GPIOD_CLK_ENABLE();
void GPIOA_CLK_DISABLE();
void GPIOB_CLK_DISABLE();
void GPIOC_CLK_DISABLE();
void GPIOD_CLK_DISABLE();

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Config *GPIO_Init);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_USART1_Init();
void GPIO_USART2_Init();
void GPIO_USART3_Init();