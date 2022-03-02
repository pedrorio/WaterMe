#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

#include "src/Battery.h"
#include "src/MoistureSensor.h"
#include "src/PeristalticPump.h"


void setup()
{
	Serial.begin(9600);
	delay(1500);
	Serial.println("OK");

	PeristalticPump::setup();
}

void loop()
{

	MoistureSensor::logData();
	Battery::logVoltage();

	if (Battery::hasCapacity())
	{
		PeristalticPump::stopMotors();
	} else 
	{
		if (!MoistureSensor::isDry())
		{
			PeristalticPump::activateMotor(30,2000);
		}
	}

	PeristalticPump::ping();
	delay(1000);
};