#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "timer.h"


int main( void ) {
	DDRC |= (1<<PC4);
	DDRC |= (1<<PC5);

	PORTC |= (1<<PC4);

	timer_init();
	sei();

	while(1) {
		PORTC ^= (1<<PC4);
		PORTC ^= (1<<PC5);
		timer_wait( 100 );
	}
}
