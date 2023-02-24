/*
 * main.c
 *
 *  Created on: Feb 21, 2023
 *      Author: LENOVO
 */

#include"main_headers.h"

type_states g_states=ideal_state;

volatile int g_SSflag=0;
volatile int clc_secTick=0;
volatile int numtick=6;
//extern void timer0_dis();


ISR(TIMER0_OVF_vect)
{
	g_SSflag++;
	clc_secTick++;
	if(g_SSflag==(numtick*7))
	{
		g_SSflag=6;
	}
	if(clc_secTick>100)
	{
		clc_secTick=0;
	}
}

void app_init()
{
	timer0_init();
	SREG|=(1<<7);
	LCD_init();
	KeyPad_init();
	sevenSeg_init();
}

int main(void)
{
	app_init();
	while(1)
	{
		switch(g_states)
		{
		case ideal_state:
			idealState();
			break;
		case SW:
			SWState();
			break;
		case RTC:
			RTCState();
			break;
		}

	}
}
