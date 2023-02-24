/*
 * idealState.c
 *
 *  Created on: Feb 22, 2023
 *      Author: LENOVO
 */
#include"main_headers.h"

extern type_states g_states;

char character=' ';

void idealState()
{
	LCD_clearScreen();
	LCD_moveCursor(1,1);
	LCD_displayString("SW--> press 1");
	LCD_moveCursor(2,1);
	LCD_displayString("RTC--> press 0");

	while(!((KeyPad_read() == '1') || (KeyPad_read() == '0'))){};
	character=KeyPad_read();
	if(character=='1')
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("SW is ON");

		g_states=SW;//in stopWatch state
	}
	else
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("RTC is ON");

		g_states=RTC;//in RTC state
	}


}

