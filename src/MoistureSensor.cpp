#include "MoistureSensor.h"

float MoistureSensor::_data = 0.0;

int MoistureSensor::getData()
{
    _data = map(analogRead(_pin), 1023, 165, 100, 0);
    _data = constrain(_data, 0, 100);
    return _data;
}

void MoistureSensor::logData()
{
    Serial.print("Soil moisture: ");
    Serial.print(getData());
    Serial.println("%");
}

bool MoistureSensor::isDry()
{
    return _data > _limit;
}