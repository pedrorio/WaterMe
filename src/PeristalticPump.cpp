#include "PeristalticPump.h"

void PeristalticPump::setup()
{
    // _controller.begin();
	controller.begin();
    // _controller.reboot();
	controller.reboot();
	delay(500);
	stopMotors();
}

void PeristalticPump::stopMotors()
{
	M1.setDuty(0);
	M2.setDuty(0);
	M3.setDuty(0);
	M4.setDuty(0);
}

void PeristalticPump::activateMotor(int duty, int interval)
{   
	M1.setDuty(duty);
	delay(2000);
	M1.setDuty(0);
}

void PeristalticPump::ping()
{
	controller.ping();
}