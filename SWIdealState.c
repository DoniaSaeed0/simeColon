/*
 * SWIdealState.c
 *
 *  Created on: Feb 22, 2023
 *      Author: LENOVO
 */
#include"main_headers.h"

extern type_states g_states;
static stopW_states SW_state =SW_idealstate;

time* zero_time;
extern char character;
void SWPauseState()
{
	swapTime(zero_time);
	LCD_clearScreen();
	LCD_moveCursor(1,1);
	LCD_displayString("continue-->0");
	LCD_moveCursor(2,1);
	LCD_displayString("start SW--> 1");
	while(!((KeyPad_read() == '0') || (KeyPad_read() == '1')));
	character=KeyPad_read();
	if(character=='0')
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("continue");

		SW_state=SW_onstate;//in stopWatch state
	}
	else
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("RTC");

		SW_state=SW_idealstate;//in RTC state
	}

}

void SWIdealState()
{
	reset(zero_time);
	sevenSegInitTime(zero_time);
	LCD_clearScreen();
	LCD_moveCursor(1,1);
	LCD_displayString("pause--> 2");
	LCD_moveCursor(2,1);
	LCD_displayString("RTC--> 3");

	while(!((KeyPad_read() == '2') || (KeyPad_read() == '3')))
	{
		calc_time();
		display_time();
	}
	character=KeyPad_read();
	if(character=='2')
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("pause");

		SW_state=SW_pausestate;//in stopWatch state
	}
	else
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("RTC");

		g_states=RTC;//in RTC state
	}


}

void SWOnState()
{
	sevenSegInitTime(zero_time);
	LCD_clearScreen();
	LCD_moveCursor(1,1);
	LCD_displayString("pause--> 2");
	LCD_moveCursor(2,1);
	LCD_displayString("RTC--> 3");

	while(!((KeyPad_read() == '2') || (KeyPad_read() == '3')))
	{
		calc_time();
		display_time();
	}
	character=KeyPad_read();
	if(character=='2')
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("pause");

		SW_state=SW_pausestate;//in stopWatch state
	}
	else
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("RTC");

		g_states=RTC;//in RTC state
	}


}

void SWState()
{
	while(g_states==SW)
	{
		switch(SW_state)
		{
		case SW_idealstate:
			SWIdealState();
			break;
		case SW_pausestate:
			SWPauseState();
			break;
		case SW_onstate:
			SWOnState();
		}
	}
}
