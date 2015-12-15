#include <avr/io.h>
#include <stdint.h>
#include "sensor.h"

// SL6 is PB0
// SL4 is PC6

void sens_init( void ) {
	DDRB &= ~(1<<PB0); // SL6 is left bumper
	DDRB &= ~(1<<PB5); // START button
	DDRC &= ~(1<<PC6); // SL4 is right bumper

}



uint8_t sens_bumper_get( void ) {
	if( PINB&(1<<PB0) ) {
		return B_LEFT; // left bumper
	}
	else if( PINC&(1<<PC6) ) {
		return B_RIGHT; // right bumper
	}

	return 0x00;
}
