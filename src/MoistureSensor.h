# ifndef MOISTURE_SENSOR_H
# define MOISTURE_SENSOR_H

#include <Arduino.h>

class MoistureSensor
{
public:
	static int getData();
	static void logData();
	static bool isDry();
private:
	static int const _pin = A2;
	static int const _limit = 30; // Unclear what is the real limit for the specific plant
	static float _data;
	MoistureSensor();
};

# endif