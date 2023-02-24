/*
 * time0.c
 *
 *  Created on: Feb 22, 2023
 *      Author: LENOVO
 */

#include"main_headers.h"

void timer0_init()
{
	TCNT0 = 0; // Set Timer initial value to 0

	TIMSK = (1<<TOIE0); // Enable Timer0 Overflow Interrupt

	/* configure the timer
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 * 4. clock = F_CPU/64 CS00=1 CS01=1 CS02=0
	 */
	TCCR0 = (1<<FOC0) | (1<<CS01) | (1<<CS00);
}
