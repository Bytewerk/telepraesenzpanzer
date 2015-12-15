#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "sensor.h"
#include "motor.h"



int main( void ) {
	uint8_t bumper;

	DDRC |= (1<<PC4);
	DDRC |= (1<<PC5);

	motor_init();
	sens_init();

	timer_init();
	sei();

	while( 1 ) {
		bumper = sens_bumper_get();

		if( bumper&B_LEFT ) {
			motor_stop( M_LEFT );
			motor_stop( M_RIGHT );
			while(1);
		}
		else if( bumper&B_RIGHT ) {
			motor_stop( M_LEFT );
			motor_stop( M_RIGHT );
			while(1);
		}
		else {
			motor_setDir( M_LEFT, M_FORWARD );
			motor_setDir( M_RIGHT, M_FORWARD );
			motor_start( M_LEFT );
			motor_start( M_RIGHT );
		}
	}
}
