#include <avr/io.h>
#include "motor.h"

void motor_init( void ) {
	PORTD &= ~(1<<PD4);
	PORTD &= ~(1<<PD5);
	PORTC &= ~(1<<PC2);
	PORTC &= ~(1<<PC3);

	DDRD |= (1<<PD4); // left motor
	DDRD |= (1<<PD5); // right motor
	DDRC |= (1<<PC2); // left motor direction output
	DDRC |= (1<<PC3); // right motor direction output
}



void motor_setDir( motor_e id, dir_e direction ) {
	if( id == M_LEFT ) {
		if( direction == M_FORWARD ) {
			PORTC &= ~(1<<PC2);
		}
		else {
			PORTC |= (1<<PC2);
		}
	}
	else if( id == M_RIGHT ) {
		if( direction == M_FORWARD ) {
			PORTC &= ~(1<<PC3);
		}
		else {
			PORTC |= (1<<PC3);
		}
	}
}



void motor_start( motor_e id ) {
	if( id == M_LEFT ) {
		PORTD |= (1<<PD4);
	}
	else if( id == M_RIGHT ) {
		PORTD |= (1<<PD5);
	}
}



void motor_stop( motor_e id ) {
	if( id == M_LEFT ) {
		PORTD &= ~(1<<PD4);
	}
	else if( id == M_RIGHT ) {
		PORTD &= ~(1<<PD5);
	}
}
