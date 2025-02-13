#include "ch32v00x.h"

uint8_t dutyCycle = 50; // Initial brightness (50%)

void GPIO_Config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;

    // Configure PA0 as Alternate Function (PWM Output)
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure PA1 and PA2 as Input (Buttons)
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void PWM_Config(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    TIM_OCInitTypeDef TIM_OCStruct;

    // Set timer frequency (PWM period)
    TIM_BaseStruct.TIM_Prescaler = 48 - 1;  // Adjust for 1MHz timer clock
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = 100 - 1;  // PWM resolution (0-100)
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIM_BaseStruct);

    // PWM Mode for PA0
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_Pulse = dutyCycle; // Initial brightness
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &TIM_OCStruct);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

    TIM_Cmd(TIM2, ENABLE);
}

void delay_ms(uint16_t ms) {
    for (volatile uint32_t i = 0; i < ms * 4000; i++); // Approximate delay
}

int main(void) {
    SystemInit();
    GPIO_Config();
    PWM_Config();

    while (1) {
        // If button PA1 is pressed (Increase brightness)
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1)) {
            if (dutyCycle < 100) dutyCycle += 10; // Increase brightness
            TIM_SetCompare1(TIM2, dutyCycle);
            delay_ms(200); // Debounce delay
        }

        // If button PA2 is pressed (Decrease brightness)
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)) {
            if (dutyCycle > 0) dutyCycle -= 10; // Decrease brightness
            TIM_SetCompare1(TIM2, dutyCycle);
            delay_ms(200); // Debounce delay
        }
    }
}
