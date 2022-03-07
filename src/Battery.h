#pragma once

#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

class Battery
{
public:
	static float getVoltage();
	static void logVoltage();
	static bool hasCapacity();

private:
	// static mc::Battery const _battery = battery;
	constexpr static float const _limit = 9.00;
	static float _voltage;
	Battery();
};