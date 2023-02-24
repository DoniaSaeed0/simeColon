/*
 * GPIO0.0.1.c
 *
 *  Created on: Oct 9, 2022
 *      Author: LENOVO
 */

#include"common_macros.h"
#include"Data_Type.h"
#include"GPIO0.0.1.h"
#include<avr/io.h>
/*
 * TO SET BITS AS OUTPUT BITS
 * this function chicks that port id is correct and num_bit is less than 7
 * if inputs are possible will make bit direction output
 */
void SET_BIT_DIRECTION_OUTPUT(uint8 PORT_ID, uint8 NUM_BIT)
{
	if((NUM_BIT>7)||!((PORT_ID=='A')||(PORT_ID=='B')||(PORT_ID=='C')||(PORT_ID=='D')))
	{
		/*DO NO THING*/
	}
	else
	{
		switch(PORT_ID)
		{
		case 'A':
			SET_BIT(DDRA,NUM_BIT);
			break;

		case 'B':
			SET_BIT(DDRB,NUM_BIT);
			break;

		case 'C':
			SET_BIT(DDRC,NUM_BIT);
			break;

		case 'D':
			SET_BIT(DDRD,NUM_BIT);
			break;
		}
	}
}
/*
 * TO SET BITS AS INPUT BIT
 * this function chicks that port id is correct and num_bit is less than 7
 * if inputs are possible will make bit direction input
 *
 */

void SET_BIT_DIRECTION_INPUT(uint8 PORT_ID, uint8 NUM_BIT)
{
	if((NUM_BIT>7)||!((PORT_ID=='A')||(PORT_ID=='B')||(PORT_ID=='C')||(PORT_ID=='D')))
	{
		/*DO NO THING*/
	}
	else
	{
		switch(PORT_ID)
		{
		case 'A':
			CLEAR_BIT(DDRA,NUM_BIT);
			break;

		case 'B':
			CLEAR_BIT(DDRB,NUM_BIT);
			break;

		case 'C':
			CLEAR_BIT(DDRC,NUM_BIT);
			break;

		case 'D':
			CLEAR_BIT(DDRD,NUM_BIT);
			break;
		}
	}
}
/*
 * TO SET ALL BITS IN ANY PORT AS OUTPUT
 *  this function chicks that port id is correct
 * if inputs are possible will make port direction output
 *
 */
void SET_PORT_DIRECTION_OUTPUT(uint8 PORT_ID)
{
	if((PORT_ID=='A')||(PORT_ID=='B')||(PORT_ID=='C')||(PORT_ID=='D'))
	{
		switch(PORT_ID)
		{
		case 'A':
			DDRA|=(0XFF);
			break;

		case 'B':
			DDRB|=(0XFF);
			break;

		case 'C':
			DDRC|=(0XFF);
			break;

		case 'D':
			DDRD|=(0XFF);
			break;

		}
	}
}
/*
 * TO SET ALL BITS IN ANY PORT AS INTPUT
 *this function chicks that port id is correct
 * if inputs are possible will make port direction input
 */
void SET_PORT_DIRECTION_INPUT(uint8 PORT_ID)
{
	if((PORT_ID=='A')||(PORT_ID=='B')||(PORT_ID=='C')||(PORT_ID=='D'))
	{
		switch(PORT_ID)
		{
		case 'A':
			DDRA&=~(0XFF);
			break;

		case 'B':
			DDRB&=~(0XFF);
			break;

		case 'C':
			DDRC&=~(0XFF);
			break;

		case 'D':
			DDRD&=~(0XFF);
			break;

		}
	}
	else
	{
		/*
		 * do no thing
		 */
	}
}
/*
 * WRITE ON ANY PORT
 * this function chicks that port id is correct
 * if inputs are possible will make clear port then write on it
 */
void WRITE_ON_PORT(uint8 PORT_ID,uint8 DATA)
{
	if((PORT_ID=='A')||(PORT_ID=='B')||(PORT_ID=='C')||(PORT_ID=='D'))
	{
		DATA&=(0XFF);
		switch(PORT_ID)
		{
		case 'A':
			PORTA&=~(0XFF);
			PORTA|=DATA;
			break;

		case 'B':
			PORTB&=~(0XFF);
			PORTB|=DATA;
			break;

		case 'C':
			PORTC&=~(0XFF);
			PORTC|=DATA;
			break;

		case 'D':
			PORTD&=~(0XFF);
			PORTD|=DATA;
			break;

		}
	}
	else
	{
		/*
		 * do no thing
		 */
	}

}
