// Ultrasound.h

#ifndef __HCSR04_H
#define __HCSR04_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _IDISTANCE_H
#include "IDistance.h"
#endif

/*
   HC-SR04 ultra sound component
*/
class HCSR04 :
	public IDistance
{
private:
	int triggerPin;
	int echoPin;

public:

	void init(int tiggerPin, int echoPin);
	double getDistance();
};

#endif

