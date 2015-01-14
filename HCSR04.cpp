
#include "HCSR04.h"

void HCSR04::init(int triggerPin, int echoPin)
{
	this->triggerPin = triggerPin;
	this->echoPin = echoPin;

	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

double HCSR04::getDistance()
{
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	long duration = pulseIn(echoPin, HIGH);
	double distance = (duration / 2) / 29.1;
	// >= 200 or <= 0 are error values, or out of range
	return distance >= 200 || distance <= 0 ? -1 : distance;
}

