// Dht11.h

#ifndef __DHT11_H
#define __DHT11_H

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

enum DHT_STATUS
{
	OK = 0,
	ERROR_CHECKSUM = -1,
	ERROR_TIMEOUT = -2
};

// DHT11 Distance and Humity sensor

class DHT11 :
	public ITemperature,
	public IHumidity
{
private:
	int digitalPin;

	double temperature;
	double humidity;
protected:

public:
	void init(int digitalPin);

	int read();

	double getTemperature();
	double getHumidity();
};

#endif

