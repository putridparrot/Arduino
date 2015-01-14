// ITemperature.h

#ifndef _ITEMPERATURE_h
#define _ITEMPERATURE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Sensor
{
	class ITemperature
	{
	public:
		virtual int getTemperature() = 0;
	};
}

#endif

