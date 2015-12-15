#include <stdint.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "timer.h"



/* timer_time gets increased on every interrupt
 * those interrupts happen every 1ms
 */
static volatile uint32_t timer_time;

ISR(TIMER2_COMP_vect) {
	++timer_time;
	return;
}

/**
 * Initialize the timer
 * This function has to be called first, before calling timer_wait and/or timer_get,
 * else timer_get will always return 0, and timer_wait will wait forever!
 */

void timer_init(void) {
	// Stop all interrupts
	cli();

	// Reset timer to zero
	timer_time = 0;

	// - Time accuracy: 1 millisecond (corresponding frequency: 1kHz)
	// ==> F_CPU = 8Mhz
	// ==> 8Mhz / 32 = 250 kHz
	// ==> let timer count to 250 to get 1kHz frequency
	// therefore:
	// - Set Timer/Counter0 prescaler to 8 ==> (1<<CS01)
	// - Set OCR2 to 249
	// - CTC ( i.e. clear counter, when COUNTER == OCR0A) ==> (1<<WGM01)
	OCR2 = 249;
	TCCR2 = (1<<CS21)|(1<<CS20)|(1<<WGM21);

	// Interrupts setzen
	TIMSK |= (1<<OCIE2);

	// Allow interrupts
	sei();
}


/**
 * Get the current time
 * \return the current time (in ms)
 */
inline uint32_t timer_getMs(void) {
	uint32_t t;
	uint8_t sreg;

	sreg = SREG;
	cli();
	t = timer_time;
	SREG = sreg;
	return t;
}

/**
 * Wait for (at least) the specified amount of time
 * \param delay The time to wait (in ms)
 */

void timer_wait(uint32_t delay) {
	uint32_t end = timer_getMs() + delay +1;
	while ( end > timer_getMs() );
	return;
}
