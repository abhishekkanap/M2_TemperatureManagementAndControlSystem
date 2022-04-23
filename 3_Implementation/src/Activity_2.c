/**
 * @file Activity_2.c
 * @author Abhishek Kanap
 * @brief LCD
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Activity_2.h"

/**
 * @brief LCD Command
 * 
 * @param cmd
 */
void LCD_CMD( unsigned char cmd )
{
	PORT_B = (PORT_B & 0x0F) | (cmd & 0xF0); // Taking Upper nibble only
	PORT_B &= ~ (1<<LCD_RS); // Making LCD_RS=0
	PORT_B |= (1<<LCD_EN); // Enabling EN=1
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (cmd << 4); //Taking Lower nibble only
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}

/**
 * @brief LCD Character wise diplaying
 * 
 * @param ch 
 */
void LCD_CHAR_WISE( unsigned char ch )
{
	PORT_B = (PORT_B & 0x0F) | (ch & 0xF0); /* sending upper nibble */
	PORT_B |= (1<<LCD_RS);		/* LCD_RS=1, ch reg. */
	PORT_B|= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);

	_delay_us(250);

	PORT_B = (PORT_B & 0x0F) | (ch << 4); /* sending lower nibble */
	PORT_B |= (1<<LCD_EN);
	_delay_us(5);
	PORT_B &= ~ (1<<LCD_EN);
	_delay_ms(50);
}

/**
 * @brief LCD Initialization
 * 
 */
void LCD_init(void)
{
	LCD_DIRECTION = 0xFF; // LCD port as output
	_delay_ms(50);

	LCD_CMD(0x02);	// 4 bit LCD
	LCD_CMD(0x28);  // 5x7 Matrix(2 line)
	LCD_CMD(0x0c);  // Display On cursor Off
	LCD_CMD(0x06);  // Increment cursor
	LCD_CMD(0x01);  // LCD Clear
	_delay_ms(5);
}

/**
 * @brief LCD String Display
 * 
 * @param temp_value 
 */
void LCD_DISPLAY (char *temp_value)
{
	int Index;
	for(Index=0;temp_value[Index]!=0;Index++)
	{
		LCD_CHAR_WISE(temp_value[Index]);
	}
}

/**
 * @brief LCD Clear
 * 
 */
void clear_LCD()
{
	LCD_CMD (0x01);	// LCD Clear
	_delay_ms(50);
	LCD_CMD (0x80);	// cursor back to start position
}
