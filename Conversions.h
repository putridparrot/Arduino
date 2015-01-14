#ifndef __CONVERSIONS_H
#define __CONVERSIONS_H

class Conversions
{
public:
	static double toFahrenheit(double fromCelsius)
	{
		return 1.8 * fromCelsius + 32;
	}

	static double toKelvin(double fromCelsius)
	{
		return fromCelsius + 273.15;
	}

	// reference (1) : http://wahiduddin.net/calc/density_algorithms.htm
	// reference (2) : http://www.colorado.edu/geography/weather_station/Geog_site/about.htm
	static double toDewPoint(double celsius, double humidity)
	{
		double ratio = 373.15 / (273.15 + celsius);
		double rhs = -7.90298 * (ratio - 1);
		rhs += 5.02808 * log10(ratio);
		rhs += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / ratio))) - 1);
		rhs += 8.1328e-3 * (pow(10, (-3.49149 * (ratio - 1))) - 1);
		rhs += log10(1013.246);

		double vp = pow(10, rhs - 3) * humidity;

		double temp = log(vp / 0.61078);
		return (241.88 * temp) / (17.558 - temp);
	}

	// delta max = 0.6544 wrt dewPoint()
	// 6.9 x faster than dewPoint()
	// reference: http://en.wikipedia.org/wiki/Dew_point
	static double toDewPointFast(double celsius, double humidity)
	{
		double a = 17.271;
		double b = 237.7;
		double temp = (a * celsius) / (b + celsius) + log(humidity * 0.01);
		return (b * temp) / (a - temp);
	}
};

#endif