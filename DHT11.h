// Dht11.h

#ifndef _DHT11_h
#define _DHT11_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef _ITEMPERATURE_h
#include "ITemperature.h"
#endif
#ifndef _IHUMIDITY_h
#include "IHumidity.h"
#endif

//namespace Sensor
//{
#define DHT_OK				 0
#define DHT_ERROR_CHECKSUM	-1
#define DHT_ERROR_TIMEOUT	-2

	class DHT11 : 
		public ITemperature, 
		public IHumidity
	{
	private:
		int digitalPin;

		int temperature;
		int humidity;
	protected:

	public:
		void init(int digitalPin);

		int read();

		int getTemperature();
		int getHumidity();
	};
//}
#endif

