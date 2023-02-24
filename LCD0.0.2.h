/*
 * LCD0.0.2.h
 *
 *  Created on: Oct 12, 2022
 *      Author: LENOVO
 */

#ifndef LCD0_0_2_H_
#define LCD0_0_2_H_
/*************************
 * USE 4 MODE OR 8 MODE LCD
 *******************/
#define LCD_MODE4
#define LCD_LINE2

#ifndef LCD_MODE4
#ifndef LCD_MODE8
#error
#endif
#endif
/******************************************************************************************************************/
#include"GPIO0.0.1.h"
/****************************************************************************************************************/
// RS IS CONNECTED TO PORT D ,PIN 4
/******************************************************************************************************************/
#define RS_PORT PORTD
#define RS_PORT_ID PORTD_ID
#define RS_PIN_ID PIN0
/****************************************************************************************************************/
// E IS CONNECTED TO PORT D ,PIN 5
/******************************************************************************************************************/
#define E_PORT PORTD
#define E_PORT_ID PORTD_ID
#define E_PIN_ID PIN1
/****************************************************************************************************************/
// LCD INPUTS ARE CONNECTED TO PORT C
/******************************************************************************************************************/
#define LCD_PORT PORTD
#define LCD_PORT_ID PORTD_ID

/*****************************************************************************************************************
 *                             COMMANDS
 ****************************************************************************************************************/
#define START_8_2_CMD 0X38// LCD MODE 8, 2LINES(START COMMAND)
#define START_8_1_CMD 0X30//LCD MODE 8, 1LINES(START COMMAND)
#define START_4_1_CMD 0X20//LCD MODE 4, 1LINES(START COMMAND)
#define START_4_2_CMD 0X28//LCD MODE 4, 2LINES(START COMMAND)
#define DISPLAY_ON_CURSOR_OFF 0X0C
#define CLEAR_SCREEN 0X01
#define FIRST_LINE 0X80
#define SECOND_LINE 0XC0
#define SHIFT_RIGHT 0X14


/*********************************************************************************************************************
 *                         functions prototypes
 ***********************************************************************************************************************/
void LCD_sendCmd(uint8 cmd);//send command to LCD
void LCD_init(void);//initialize LCD
void LCD_displayCharacter(uint8 data);//display character on LCD screen
void LCD_displayString(const uint8*str);//display string on LCD screen
void LCD_clearScreen();//clear LCD screen
void LCD_moveCursor(uint8 row,uint8 colum);//control cursor
void LCD_intgerToString(int data);//display integer numbers
void LCD_shiftCursorLeft(uint8 num);//shift cursor left
void LCD_shiftCursorRight(uint8 num);






#endif /* LCD0_0_2_H_ */
