// Ultrasound.h

#ifndef _ULTRASOUND_h
#define _ULTRASOUND_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*
   HC-SR04 ultra sound component
*/
class HCSR04
{
private:
	int triggerPin;
	int echoPin;

protected:


public:

	void init(int tiggerPin, int echoPin);
	long ping();
};

#endif

