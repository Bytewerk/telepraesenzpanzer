#include <avr/io.h>
#include <stdint.h>
#include "sensor.h"

// SL6 is PB0
// SL4 is PC6

void sens_init( void ) {
	DDRB &= ~(1<<PB0); // SL6 is left bumper
	DDRC &= ~(1<<PC6); // SL4 is right bumper

}



uint8_t sens_bumper_get( void ) {
	if( PINB&(1<<PB0) ) {
		return 0x01; // left bumper
	}
	else if( PINC&(1<<PC6) ) {
		return 0x02; // right bumper
	}

	return 0x00;
}
