#ifndef __MOTOR_H__
#define __MOTOR_H__


typedef enum {
	M_FORWARD = 0x01,
	M_BACK    = 0x02
} dir_e;

typedef enum {
	M_LEFT  = 0x01,
	M_RIGHT = 0x02
} motor_e;



void motor_init( void );
void motor_setDir( motor_e id, dir_e direction );
void motor_start( motor_e id );
void motor_stop( motor_e id );


#else
#error "double include of motor.h"
#endif
