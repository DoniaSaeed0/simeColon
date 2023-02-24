/*
 * GPIO0.0.1.h
 *
 *  Created on: Oct 9, 2022
 *      Author: LENOVO
 */

#ifndef GPIO0_0_1_H_
#define GPIO0_0_1_H_
/***************************************************************************************************************************************************************************************/
#include"Data_Type.h"
/*********************************************************************************************************************************************************************************
 *
 *  define number of ports is 4
 *  define number of pins per any port is 7
 *
 ********************************************************************************************************************************************************************************/
#define NUM_PORTS 4 /*atmega32 has only 4 ports*/
#define NUM_PER_PORTS 7/* any number from 0>>7 will be accepted*/
/******************************************************************************************************************************************************************************************/
#define PORTA_ID 'A'
#define PORTB_ID 'B'
#define PORTC_ID 'C'
#define PORTD_ID 'D'
/*********************************************************************************************************************************************************************************
 *
 *                          FUNCTION DECLERAION
 *
 * SET_BIT_DIRECTION_OUTPUT,this function get port id and num_bit id TO SET PIN IN THIS PORT AS OUTPUT DIRECTION
 * SET_BIT_DIRECTION_INPUT,this function get port id and num_bit id TO SET PIN IN THIS PORT AS INTPUT DIRECTION
 * SET_PORT_DIRECTION_OUTPUT,this function get port id TO SET ALL PINS IN THIS PORT AS OUTPUT DIRECTION
 * SET_PORT_DIRECTION_INTPUT,this function get port id TO SET ALL PINS IN THIS PORT AS INTPUT DIRECTION
 * WRITE_ON_PORT,this function gets port id to write on it
 *
 ********************************************************************************************************************************************************************************/

void SET_BIT_DIRECTION_OUTPUT(uint8 PORT_ID, uint8 NUM_BIT);
void SET_BIT_DIRECTION_INPUT(uint8 PORT_ID, uint8 NUM_BIT);
void SET_PORT_DIRECTION_OUTPUT(uint8 PORT_ID);
void SET_PORT_DIRECTION_INPUT(uint8 PORT_ID);
void WRITE_ON_PORT(uint8 PORT_ID,uint8 DATA);

/*********************************************************************************************************************************************************************************
 *
 *
 ********************************************************************************************************************************************************************************/


#endif /* GPIO0_0_1_H_ */
