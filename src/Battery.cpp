#include "Battery.h"

float Battery::_voltage = 0.0;

float Battery::getVoltage()
{
    _voltage = (float) battery.getRaw() / 77;
    return _voltage;
}

void Battery::logVoltage()
{
    Serial.print("Battery voltage: ");
    Serial.println(getVoltage());
}

bool Battery::hasCapacity()
{
    return getVoltage() < _limit;
}