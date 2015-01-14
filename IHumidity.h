// IHumidity.h

#ifndef _IHUMIDITY_h
#define _IHUMIDITY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Sensor
{
	class IHumidity
	{
	public:
		virtual int getHumidity() = 0;
	};

}
#endif

