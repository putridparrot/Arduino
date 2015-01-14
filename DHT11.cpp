#include "DHT11.h"

void DHT11::init(int digitalPin)
{
	this->digitalPin = digitalPin;
}

int DHT11::read()
{
	uint8_t bits[5];
	uint8_t count = 7;
	uint8_t idx = 0;

	memset(bits, 0, 5);

	// REQUEST SAMPLE
	pinMode(digitalPin, OUTPUT);
	digitalWrite(digitalPin, LOW);
	delay(18);
	digitalWrite(digitalPin, HIGH);
	delayMicroseconds(40);
	pinMode(digitalPin, INPUT);

	// ACKNOWLEDGE or TIMEOUT
	unsigned int loopCnt = 10000;
	while (digitalRead(digitalPin) == LOW)
	{
		if (loopCnt-- == 0)
			return ERROR_TIMEOUT;
	}

	loopCnt = 10000;
	while (digitalRead(digitalPin) == HIGH)
	{
		if (loopCnt-- == 0)
			return ERROR_TIMEOUT;
	}

	// READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT
	for (int i = 0; i < 40; i++)
	{
		loopCnt = 10000;
		while (digitalRead(digitalPin) == LOW)
		{
			if (loopCnt-- == 0)
				return ERROR_TIMEOUT;
		}

		unsigned long t = micros();

		loopCnt = 10000;
		while (digitalRead(digitalPin) == HIGH)
		{
			if (loopCnt-- == 0)
				return ERROR_TIMEOUT;
		}

		if ((micros() - t) > 40)
			bits[idx] |= (1 << count);

		if (count == 0)   // next byte?
		{
			count = 7;    // restart at MSB
			idx++;      // next byte!
		}
		else
		{
			count--;
		}
	}

	// WRITE TO RIGHT VARS
	// as bits[1] and bits[3] are allways zero they are omitted in formulas.
	humidity = bits[0];
	temperature = bits[2];

	uint8_t sum = bits[0] + bits[2];

	return (bits[4] != sum) ? ERROR_CHECKSUM : OK;
}

double DHT11::getTemperature()
{
	return temperature;
}

double DHT11::getHumidity()
{
	return humidity;
}
