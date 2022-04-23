/**
 * @file Activity_2.h
 * @author Abhishek Kanap
 * @brief LCD
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */
#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED

#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#define LCD_DIRECTION  DDRB			/* Define LCD data port direction */
#define PORT_B PORTB			/* Define LCD data port */
#define LCD_RS PB2				/* Define Register Select pin */
#define LCD_EN PB3 				/* Define Enable signal pin */

void LCD_CMD( unsigned char cmd );
void LCD_CHAR_WISE( unsigned char ch );
void LCD_init(void);
void LCD_DISPLAY (char *temp_value);
void clear_LCD();

#endif // ACTIVITY_2_H_INCLUDED
