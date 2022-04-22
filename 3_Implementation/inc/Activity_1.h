/**
 * @file Activity_1.h
 * @author Abhishek Kanap
 * @brief Initialization of seat, heater and led
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED

#include <avr/io.h>
#include<util/delay.h>

#define SEAT_CHECK !(PIND &(1<<PD1))
#define HEATER_ON (PIND &(1<<PD2))
#define HEATER_OFF PORTD&=~(1<<PD2)
#define LED_ON PORTD|=(1<<PD0)
#define LED_OFF PORTD &=~(1<<PD0)

void SEAT_checking();

#endif // ACTIVITY_1_H_INCLUDED
