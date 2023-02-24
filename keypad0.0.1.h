/*
 * keypad0.0.01.h
 *
 *  Created on: Oct 26, 2022
 *      Author: LENOVO
 */

#ifndef KEYPAD0_0_1_H_
#define KEYPAD0_0_1_H_
/************************Definitions******************************************/
#define KEYPAD_PORT PORTB//connect keypad to port B as (A->PIN7 ); (B->>PIN6); (C->>PIN5); (D->>PIN4); (1->>PIN3); (2->>PIN2); (3->>PIN1); (4->>PIN0)
#define KEYPAD_PORT_ID PORTB_ID
#define KEYPAD_PIN PINB
/***********************includes******************************************/
#include"Data_Type.h"

/**************************function prototypes******************************/
/*
 * this function set pins that connected to keypad as output and input pins
 */
void KeyPad_init(void);
/*
 * this function read the output of keypad as character
 */
uint8 KeyPad_read(void);
/*
 * this function return output of keypad as number
 */
uint8 returnNumber();
#endif /* KEYPAD0_0_1_H_ */
