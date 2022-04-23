/**
 * @file Activity_3.c
 * @author Abhishek Kanap
 * @brief ADC and PWM
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Activity_2.h"
#include "Activity_3.h"

/**
 * @brief ADC Initialization
 * 
 */
void ADC_init()
{
    ADMUX=(1<<REFS0);   //AVCC = +5V
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

/**
 * @brief Reading the ADC channel 0
 * 
 * @param channel 
 * @return uint16_t 
 */
uint16_t SENSE_ADC(uint8_t channel)
{
    // Making ADC to accept channels from 0-7
    ADMUX&=0xf8;
    channel=channel&0b00000111;
    ADMUX|=channel;

    ADCSRA|=(1<<ADSC); //Enable Conversion

    while(!(ADCSRA & (1<<ADIF))); // Transferring the data

    ADCSRA|=(1<<ADIF); // ADIF=0
    return(ADC);
}

/**
 * @brief Timer 1 Initialization
 * 
 */
void TIMER_init(void){

    TIMER1_FAST_PWM;
    TIMER_PRESCALER_AS_64;
    PWM_OUTPUT_PIN;
}

/**
 * @brief PWM Output as Fast PWM
 * 
 * @param ADC_READING 
 */
void PWM_OUPUT(uint16_t ADC_READING){
    char Temp[20];
    char start[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; // Duty cycle 20%
        Temp[0] = '2';
        Temp[1] = '0';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495; // Duty cycle 40%
        Temp[0] = '2';
        Temp[1] = '5';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;// Duty cycle 70%
        Temp[0] = '2';
        Temp[1] = '9';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; // Duty cycle 95%
        Temp[0] = '3';
        Temp[1] = '3';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }
    else{
        OCR1A = 0; // Duty cycle 0%
        Temp[0] = 'O';
        Temp[1] = 'F';
        Temp[2] = 'F';
        Temp[3] = ' ';
        Temp[4] = '\0';
        LCD_DISPLAY(start);
        LCD_CMD(0xC0);
        LCD_DISPLAY(Temp);
        _delay_ms(20);
    }

}
