#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "sensor.h"



int main( void ) {
	uint8_t bumper;

	DDRC |= (1<<PC4);
	DDRC |= (1<<PC5);

	timer_init();
	sens_init();
	sei();

	while(1) {
		bumper = sens_bumper_get();

		if( bumper&0x01 ) {
			PORTC |= (1<<PC4);
		}
		else if( bumper&0x02 ) {
			PORTC |= (1<<PC5);
		}
		else {
			PORTC &= ~(1<<PC4);
			PORTC &= ~(1<<PC5);
		}

		timer_wait( 100 );
	}
}
