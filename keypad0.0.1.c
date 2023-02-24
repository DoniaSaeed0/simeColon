/*
 * keypad0.0.1.c
 *
 *  Created on: Oct 26, 2022
 *      Author: LENOVO
 */

#include "keypad0.0.1.h"
#include"GPIO0.0.1.h"
#include <avr/io.h>
#include "common_macros.h"
#include "LCD0.0.2.h"
#include <util/delay.h>

int delay =10;
void KeyPad_init(void)
{
	//output pins
	SET_BIT_DIRECTION_OUTPUT(KEYPAD_PORT_ID,PIN4);
	SET_BIT_DIRECTION_OUTPUT(KEYPAD_PORT_ID,PIN5);
	SET_BIT_DIRECTION_OUTPUT(KEYPAD_PORT_ID,PIN6);
	SET_BIT_DIRECTION_OUTPUT(KEYPAD_PORT_ID,PIN7);
	//input pins
	SET_BIT_DIRECTION_INPUT(KEYPAD_PORT_ID,PIN0);
	SET_BIT_DIRECTION_INPUT(KEYPAD_PORT_ID,PIN1);
	SET_BIT_DIRECTION_INPUT(KEYPAD_PORT_ID,PIN2);
	SET_BIT_DIRECTION_INPUT(KEYPAD_PORT_ID,PIN3);
}

uint8 KeyPad_read(void)
{
	KEYPAD_PORT&=~(0X0F<<4);
	KEYPAD_PORT|=(1<<7);
	if(KEYPAD_PIN&(1<<3))
	{
        return '7';
	}
	else if(KEYPAD_PIN&(1<<2))
	{
        return '8';
	}
	else if(KEYPAD_PIN&(1<<1))
	{
        return '9';
	}
	else if(KEYPAD_PIN&(1<<0))
	{
        return '%';
	}
    _delay_ms(delay);

	KEYPAD_PORT&=~(0X0F<<4);
	KEYPAD_PORT|=(1<<6);
	if(KEYPAD_PIN&(1<<3))
	{
        return '4';
	}
	else if(KEYPAD_PIN&(1<<2))
	{
        return '5';
	}
	else if(KEYPAD_PIN&(1<<1))
	{
		return '6';
	}
	else if(KEYPAD_PIN&(1<<0))
	{
        return '*';
	}
	_delay_ms(delay);


	KEYPAD_PORT&=~(0X0F<<4);
	KEYPAD_PORT|=(1<<5);
	if(KEYPAD_PIN&(1<<3))
	{
        return '1';
	}
	else if(KEYPAD_PIN&(1<<2))
	{
        return '2';
	}
	else if(KEYPAD_PIN&(1<<1))
	{
		return '3';
	}
	else if(KEYPAD_PIN&(1<<0))
	{
        return '-';
	}
	_delay_ms(delay);

	KEYPAD_PORT&=~(0X0F<<4);
	KEYPAD_PORT|=(1<<4);
	if(KEYPAD_PIN&(1<<3))
	{//enter button
        return 13;
	}
	else if(KEYPAD_PIN&(1<<2))
	{
        return '0';
	}
	else if(KEYPAD_PIN&(1<<1))
	{
        return '=';
	}
	else if(KEYPAD_PIN&(1<<0))
	{
       return '+';
	}
	_delay_ms(delay);

	return ' ';
}

uint8 returnNumber()
{
	switch(KeyPad_read())
	{
	case '1':
		return 1;
	case'2':
		return 2;
	case '3':
		return 3;
	case'4':
		return 4;
	case '5':
		return 5;
	case'6':
		return 6;
	case '7':
		return 7;
	case'8':
		return 8;
	case '9':
		return 9;
	case'0':
		return 0;
	}
	return ' ';
}
