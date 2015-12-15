#ifndef __SENSOR_H_
#define __SENSOR_H_

	typedef enum {
		B_LEFT  = 0x01,
		B_RIGHT = 0x02
	} bumper_e;



	void sens_init( void );
	uint8_t sens_bumper_get( void );

#else
#error "double include of sensor.h"
#endif
