#ifndef __SENSOR_H_
#define __SENSOR_H_
	void sens_init( void );
	uint8_t sens_bumper_get( void );

#else
#error "double include of sensor.h"
#endif
