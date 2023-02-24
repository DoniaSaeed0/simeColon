/*
 * main_headers.h
 *
 *  Created on: Feb 21, 2023
 *      Author: LENOVO
 */

#ifndef MAIN_HEADERS_H_
#define MAIN_HEADERS_H_

#include "keypad0.0.1.h"
#include "LCD0.0.2.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

typedef struct{
	unsigned char min[2];
	unsigned char sec[2];
	unsigned char hour[2];

}time;

typedef enum{
	ideal_state,RTC,SW
}type_states;

typedef enum{
	SW_idealstate,SW_pausestate,SW_onstate
}stopW_states;

typedef enum{
	RTC_initstate,RTC_ONstate
}RTC_Typestates;

void sevenSeg_init();
void sevenSegInitTime( time* init_time);
void swapTime(time* ptr);
void reset();
void calc_time();
void display_time();
void timer0_init();
void idealState();
void SWState();
void RTCState();


#endif /* MAIN_HEADERS_H_ */
