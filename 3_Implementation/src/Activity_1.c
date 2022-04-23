/**
 * @file Activity_1.c
 * @author Abhishek Kanap
 * @brief Seat Checking
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Activity_1.h"

/**
 * @brief Seating Checking and connfiguring the seat, heater and LED
 * 
 */
void SEAT_cheaking(){
    DDRD|=(1<<PD0); //Setting PDO pin
    DDRD&=~(1<<PD1); //clearing PD1 pin
    PORTD|=(1<<PD1); //Setting PD1 pin
    DDRD&=~(1<<PD2); //clearing PD2 pin
    PORTD|=(1<<PD2); //Setting PD2 pin
}
