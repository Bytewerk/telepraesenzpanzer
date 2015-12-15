#if !defined __TIMER_H
#define __TIMER_H

void timer_wait( uint32_t delay /*ms*/ );
uint32_t timer_getMs( void );
void timer_init( void );
void timer_decode( uint32_t time, uint8_t *hours, uint8_t *minutes, uint8_t *seconds, uint16_t *ms );
void timer_encode( uint32_t *time, uint8_t hour, uint8_t minute, uint8_t seconds, uint16_t ms );

#else
#error "double include of timer.h"
#endif
