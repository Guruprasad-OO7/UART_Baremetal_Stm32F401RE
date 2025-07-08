#include "stm32f4xx.h"
void UART2_Init(void);
void UART2_SendChar(char c);
void UART2_SendString(const char* str);
int main(void)
{
    UART2_Init();
    while (1)
    {
        UART2_SendString("Hello from STM32!\r\n");
        for (volatile int i=0;i<1000000;i++);
    }
}
void UART2_Init(void)
{
    RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &=~(3<<(2*2));
    GPIOA->MODER |=(2<<(2*2));
    GPIOA->AFR[0] &=~(0xF<<(2 * 4));
    GPIOA->AFR[0] |=(7<<(2*4));
    RCC->APB1ENR |=RCC_APB1ENR_USART2EN;
    USART2->BRR =0x0683;
    USART2->CR1 |=USART_CR1_TE;
    USART2->CR1 |=USART_CR1_UE;
}
void UART2_SendChar(char c)
{
    while (!(USART2->SR&USART_SR_TXE));
    USART2->DR = c;
}
void UART2_SendString(const char*str)
{
    while (*str)
    {
        UART2_SendChar(*str++);
    }
}
