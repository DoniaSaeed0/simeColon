/*
 * LCD0.0.2.c
 *
 *  Created on: Oct 12, 2022
 *      Author: LENOVO
 */
/**************************************************************************************************************************************************************************************************************/
#include<avr/io.h>
#include<util/delay.h>
#include"GPIO0.0.1.h"
#include"Data_Type.h"
#include"common_macros.h"
#include"LCD0.0.2.h"
#include"stdlib.h"
/**************************************************************************************************************************************************************************************************************/
/* set pin of RS as output pin
 * set pin of enable as output pin
 * set LCD inputs pins as output pins
 * SEND COMMAND to LCD to START
 * Display screen of LCD
 * Clear screen of LCD
 */
void LCD_init(void)
{
	SET_BIT_DIRECTION_OUTPUT(RS_PORT_ID,RS_PIN_ID);
	SET_BIT_DIRECTION_OUTPUT(E_PORT_ID,E_PIN_ID);
	SET_BIT(RS_PORT,RS_PIN_ID);
	_delay_ms(1);
#ifdef LCD_MODE8
	SET_PORT_DIRECTION_OUTPUT(LCD_PORT_ID);
#endif
#ifdef LCD_MODE4
	SET_BIT_DIRECTION_OUTPUT(LCD_PORT_ID,PIN7);
	SET_BIT_DIRECTION_OUTPUT(LCD_PORT_ID,PIN6);
	SET_BIT_DIRECTION_OUTPUT(LCD_PORT_ID,PIN5);
	SET_BIT_DIRECTION_OUTPUT(LCD_PORT_ID,PIN4);
	LCD_sendCmd(0x33);
	LCD_sendCmd(0x32);

#endif
#ifdef LCD_MODE8
#ifdef LCD_LINE2
	LCD_sendCmd(START_8_2_CMD);
#endif
#ifdef LCD_LINE1
	LCD_sendCmd(START_8_1_CMD);
#endif
#endif

#ifdef LCD_MODE4
#ifdef LCD_LINE2
	LCD_sendCmd(START_4_2_CMD);
#endif
#ifdef LCD_LINE1
	LCD_sendCmd(START_4_1_CMD);
#endif
#endif
	_delay_ms(1);
	LCD_sendCmd(DISPLAY_ON_CURSOR_OFF);
	LCD_sendCmd(CLEAR_SCREEN);
}
/*
 * Function responsible for write on LCD port
 */
void LCD_writeCmd(uint8 cmd)
{
#ifdef LCD_MODE4
LCD_PORT&=~(0XF0);//CLEAR BITS
LCD_PORT|=(cmd&(0xf0));//SEND UPPER 4_BITS OF COMMAND OR DATA
_delay_ms(1);
CLEAR_BIT(E_PORT,E_PIN_ID);//E=0
_delay_ms(1);
SET_BIT(E_PORT,E_PIN_ID);//E=1
_delay_ms(1);
LCD_PORT&=~(0XF0);//CLEAR UPPER 4_BITS
LCD_PORT|=((cmd&(0x0F))<<4);//SEND LOWER 4_BITS OF COMMAND OR DATA
#endif
#ifdef LCD_MODE8
	LCD_PORT=cmd;//WRITE COMMAND ON LCD_PORT
#endif
}
/*
 * to send command to LCD:
 * Clear RS pin
 * SET Enable pin
 * Write command on LCD port
 * Clear enable pin
 */
void LCD_sendCmd(uint8 cmd)
{
	CLEAR_BIT(RS_PORT,RS_PIN_ID);//RS=0
	_delay_ms(1);
	SET_BIT(E_PORT,E_PIN_ID);//E=1
	_delay_ms(1);
	LCD_writeCmd(cmd);//SEND DATA OR COMMAND
	_delay_ms(1);
	CLEAR_BIT(E_PORT,E_PIN_ID);//E=0
}
/*
 * to display character on LCD:
 * SET RS pin
 * SET Enable pin
 * Write CHAR on LCD port
 * Clear enable pin
 */

void LCD_displayCharacter(uint8 data)
{
	SET_BIT(RS_PORT,RS_PIN_ID);
	_delay_ms(1);
	SET_BIT(E_PORT,E_PIN_ID);
	_delay_ms(1);
	LCD_writeCmd(data);
	_delay_ms(1);
	CLEAR_BIT(E_PORT,E_PIN_ID);
}
/*
 * to display string on LCD screen:
 * send character by character to LCD
 */
void LCD_displayString(const uint8 *str)
{
	int i=0;
	while(str[i] !='\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}
/*
 * to Clear Screen of LCD ,Send command CLEAR_SCREEN
 */
void LCD_clearScreen()
{
	LCD_sendCmd(CLEAR_SCREEN);
}
/*
 * to move cursor to the specific position :
 * calculate the position then send it as command
 */
void LCD_moveCursor(uint8 row,uint8 colum)
{
	if(row==1)
	{
		LCD_sendCmd(FIRST_LINE+colum);
	}
	if(row==2)
	{
		LCD_sendCmd((FIRST_LINE|0x40)+colum);
	}
	if(row==3)
	{
		LCD_sendCmd((FIRST_LINE|0x10)+colum);
	}
	if(row==4)
	{
		LCD_sendCmd((FIRST_LINE|0x50)+colum);
	}


}
void LCD_intgerToString(int data)
{
  char buff[16]; /* String to hold the ascii result */
  itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
  LCD_displayString(buff); /* Display the string */
}
void LCD_shiftCursorLeft(uint8 num)
{
	for(int i=0;i<num;i++)
	{
		LCD_sendCmd(0x10);
	}
}
void LCD_shiftCursorRight(uint8 num)
{
	for(int i=0;i<num;i++)
	{
		LCD_sendCmd(0x14);
	}
}

