#include "IDistance.h"
#include "HCSR04.h"

HCSR04 sensor;

void setup()
{
	Serial.begin(115200);
	Serial.println("HCSR04 Example");
	Serial.println();

	sensor.init(3, 2);
}

void loop()
{
	Serial.println(sensor.getDistance());
	Serial.println(" cm");
}
