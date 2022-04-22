/**
 * @file main.c
 * @author Abhishek Kanap
 * @brief Temperature Monitoring System
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <avr/io.h>
#include<util/delay.h>
#include "Activity_1.h"
#include "Activity_2.h"
#include"Activity_3.h"

int main(void)
{
    SEAT_CHECKING(); //Initializing Drivers seat
    ADC_INITIALIZATION(); //Initializing ADC to accept temperature values
    TIMER_INITIALIZATION(); //Initializing Timer by dividing clock with 64 prescale
    LCD_INITIALIZATION(); //Initializing LCD

    uint16_t read;

	while(1)
    {
        if(SEAT_CHECK)
        {
            PORTD|=(1<<PD2);
            if(HEATER_ON){
                led_ON;
                _delay_ms(200);
                clear_LCD();
                read=SENSE_ADC(0);
                PWM_OUPUT(read);

            }
            else
                {
                    led_OFF;
                     _delay_ms(200);
                    HEATER_OFF;
                    _delay_ms(200);
                    clear_LCD();
                }
        }
        else{
            led_OFF;
            _delay_ms(200);
            HEATER_OFF;
            _delay_ms(200);
            clear_LCD();
        }
    }
    return 0;
}
