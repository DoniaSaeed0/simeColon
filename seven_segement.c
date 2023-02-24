/*
 * 7_segement.c
 *
 *  Created on: Feb 21, 2023
 *      Author: LENOVO
 */
#include "main_headers.h"

static time* seg_time;
extern int numtick;
void sevenSeg_init()
{
	DDRC|=(0XF);//PORT C IS OUTPUT
	PORTC=(PORTC&(0XF0))|(0X0);//PORT C= ZERO AS INITIAL VALUE
	DDRA|=(0X3f);//PORT A IS OUTPUT
	PORTA|=(0X3f);
}
void swapTime(time* ptr)
{
	ptr->hour[1]=seg_time->hour[1];
	ptr->hour[0]=seg_time->hour[0];
	ptr->min[1]=seg_time->min[1];
	ptr->min[0]=seg_time->min[0];
	ptr->sec[1]=seg_time->sec[1];
	ptr->sec[0]=seg_time->sec[0];
}
void sevenSegInitTime(time *init_time)
{
	seg_time->hour[1]=init_time->hour[1];
	seg_time->hour[0]=init_time->hour[0];
	seg_time->min[1]=init_time->min[1];
	seg_time->min[0]=init_time->min[0];
	seg_time->sec[1]=init_time->sec[1];
	seg_time->sec[0]=init_time->sec[0];
}

extern volatile int g_SSflag;
extern volatile int clc_secTick;


void reset(time *init_time)//reset
{
	init_time->min[0]=0;
	init_time->min[1]=0;
	init_time->sec[0]=0;
	init_time->sec[1]=0;
	init_time->hour[0]=0;
	init_time->hour[1]=0;
}

void display_time()
{

	if(g_SSflag==numtick)
	{
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("display");
		PORTA&=~(0X3f);
		PORTA|=(1<<5);
		PORTC=(PORTC&~(0XF))|seg_time->sec[0];
		while(!(PORTC==seg_time->sec[0]));
		//_delay_ms(5);
	}

	else if(g_SSflag==(numtick*2))
	{
		PORTA&=~(0X3f);
		PORTA|=(1<<4);

		PORTC=(PORTC&~(0XF))|seg_time->sec[1];
		while(!(PORTC==seg_time->sec[1]));
		//_delay_ms(5);
	}

	else if(g_SSflag==(numtick*3))
	{
		PORTA&=~(0X3f);
		PORTA|=(1<<3);

		PORTC=(PORTC&~(0XF))|seg_time->min[0];
		while(!(PORTC==seg_time->min[0]));
		//_delay_ms(5);
	}

	else if(g_SSflag==(numtick*4))
	{

		PORTA&=~(0X3f);
		PORTA|=(1<<2);

		PORTC=(PORTC&~(0XF))|seg_time->min[1];
		while(!(PORTC==seg_time->min[1]));
		//_delay_ms(5);
	}

	else if(g_SSflag==(numtick*5))
	{

		PORTA&=~(0X3f);
		PORTA|=(1<<1);

		PORTC=(PORTC&~(0XF))|seg_time->hour[0];
		while(!(PORTC==seg_time->hour[0]));
		//_delay_ms(5);
	}

	else if(g_SSflag==(numtick*6))
	{

		PORTA&=~(0X3f);
		PORTA|=(1<<0);

		PORTC=(PORTC&~(0XF))|seg_time->hour[1];
		while(!(PORTC==seg_time->hour[1]));

	}


}

void calc_time()
{
	//if(g_flag)
	if(clc_secTick==100)// after 1 second
	{
		// clear g_tick
		LCD_clearScreen();
		LCD_moveCursor(1,1);
		LCD_displayString("calc");
		if(seg_time->sec[0]<9)//calculate number of seconds
		{
			seg_time->sec[0]++;
		}
		else if(seg_time->sec[0]>=9)
		{
			seg_time->sec[0]=0;
			seg_time->sec[1]++;
		}
		if((seg_time->sec[1]>5))
		{
			seg_time->sec[1]=0;
			seg_time->sec[0]=0;
			if(seg_time->min[0]<9)//after 59 second calculate number of min;
			{
				seg_time->min[0]++;
			}
			else if(seg_time->min[0]>=9)
			{
				seg_time->min[0]=0;
				seg_time->min[1]++;
			}
		}
		if((seg_time->min[1]>5))
		{
			seg_time->min[1]=0;
			seg_time->min[0]=0;
			if(seg_time->hour[0]<9)
			{
				seg_time->hour[0]++;
			}
			else if(seg_time->hour[0]>=9)
			{
				seg_time->hour[0]=0;
				seg_time->hour[1]++;
			}
		}
		if((seg_time->hour[1]==2)&&(seg_time->hour[0]==4))
		{
			reset(seg_time);
		}

	}


}


