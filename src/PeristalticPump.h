# ifndef PERISTALTIC_PUMP_H
# define PERISTALTIC_PUMP_H

#include <Arduino.h>
#include <ArduinoMotorCarrier.h>

class PeristalticPump
{
public:
	static void setup();
	static void stopMotors();
	static void activateMotor(int duty, int interval);
	static void ping();
private:
	PeristalticPump();
	// static mc::MotorController _controller = controller;
	// static d21::DCMotor _motors [4] = {M1, M2, M3, M4};
	// static mc::DCMotor _motors [4] = {M1, M2, M3, M4};
};


# endif