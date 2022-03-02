#include <ArduinoMotorCarrier.h>

static const int moisturePin = A2;

static float moistureData;
static int moistureLimit = 30; // Unclear what is the real limit for the specific plant

static float batteryVoltage;
static float lowBatteryLimit = lowBatteryLimit = 5.00; // currently a 9v battery, should be changed for a better power supply

float getBatteryVoltage()
{
    batteryVoltage = (float) battery.getRaw() / 77;
    return batteryVoltage;
}

void logBatteryVoltage(float batteryVoltage)
{
    Serial.print("Battery voltage: ");
    Serial.println(batteryVoltage);
}

int getMoistureData()
{
    moistureData = map(analogRead(moisturePin), 1023, 165, 100, 0);
    moistureData = constrain(moistureData, 0, 100);
    return moistureData;
}

void logMoistureData(int moistureData)
{
    Serial.print("Soil moisture: ");
    Serial.print(moistureData);
    Serial.println("%");
}

void stopAllMotors()
{
    M1.setDuty(0);
    M2.setDuty(0);
    M3.setDuty(0);
    M4.setDuty(0);
}


void setup()
{
    Serial.begin(9600);
    delay(1500);

    controller.begin();
    controller.reboot();
    delay(500);

    stopAllMotors();
}

void loop()
{
    moistureData = getMoistureData();
    logMoistureData(moistureData);

    batteryVoltage = getBatteryVoltage();
    logBatteryVoltage(batteryVoltage);

    if (batteryVoltage < lowBatteryLimit)
    {
        stopAllMotors();
    } else
    {
        if (moistureData < moistureLimit)
        {
            M1.setDuty(30);
            delay(2000);
            M1.setDuty(0);
        }
    }

    controller.ping();
    delay(1000 * 60); // 1 hour
}