#include "debug.h"

#define LED_PIN GPIO_Pin_0  // The LED pin
#define POT_PIN GPIO_Pin_1  // The potentiometer pin (ADC input)

// Initialize GPIO pins for LED control and potentiometer input
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // Enable GPIO clock for LED and potentiometer
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // Configure GPIO pin for LED as output
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    // Configure GPIO pin for potentiometer as input (ADC channel)
    GPIO_InitStructure.GPIO_Pin = POT_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

// Initialize ADC for reading potentiometer value
void ADC_Init_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    // Configure ADC settings
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);

    // Enable ADC
    ADC_Cmd(ADC1, ENABLE);

    // Start ADC calibration
    ADC_ResetCalibration(ADC1);
    while (ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1));

    // Enable ADC conversion
    ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_55Cycles5);
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

// Read potentiometer value from ADC
uint16_t Read_Potentiometer(void)
{
    // Wait for the conversion to complete
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);

    // Get the ADC value
    return ADC_GetConversionValue(ADC1);
}

// Initialize PWM for controlling LED brightness
void PWM_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    // Enable the clock for the timer
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    // Timer configuration for PWM
    TIM_TimeBaseStructure.TIM_Period = 999;               // Frequency (adjust as needed)
    TIM_TimeBaseStructure.TIM_Prescaler = 71;              // Prescaler (adjust for desired frequency)
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    // PWM Mode configuration
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCFastMode = TIM_OCFast_Disable;
    TIM_OCInitStructure.TIM_Pulse = 0; // Initial duty cycle is 0 (LED off)
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);

    // Enable the PWM output
    TIM_Cmd(TIM1, ENABLE);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
}

// Update PWM duty cycle to control LED brightness
void Set_LED_Brightness(uint16_t value)
{
    // Adjust the duty cycle based on potentiometer value
    uint16_t pwm_duty = (value * 999) / 4095;  // Scale to 0-999 for PWM range
    TIM_SetCompare1(TIM1, pwm_duty);
}

int main(void)
{
    uint16_t potentiometer_value;

    // Initialize system
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    // Initialize GPIO, ADC, and PWM
    LED_Init();
    ADC_Init_Config();
    PWM_Init();

    // Infinite loop to control LED brightness
    while (1)
    {
        // Read potentiometer value (ADC)
        potentiometer_value = Read_Potentiometer();

        // Update LED brightness based on potentiometer value
        Set_LED_Brightness(potentiometer_value);

        // Add a small delay to debounce potentiometer changes
        Delay_Ms(50);
    }

    return 0;
}
