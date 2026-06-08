#include "sensors.h"

SensorData motorSensors;
static unsigned int simCounter = 0;

void SENSORS_Init(void) {
    motorSensors.temperature = 45;
    motorSensors.vibration = 30;
    motorSensors.rpm = 2000;
    simCounter = 0;
}

void SENSORS_Read(void) {
    simCounter++;
    if(simCounter < 50) {
        motorSensors.temperature = 45 + simCounter;
        motorSensors.vibration = 30 + simCounter;
        motorSensors.rpm = 2000;
    }
    else if(simCounter < 100) {
        motorSensors.temperature = 70 + (simCounter - 50);
        motorSensors.vibration = 65 + (simCounter - 50);
        motorSensors.rpm = 1800;
    }
    else {
        motorSensors.temperature = 90;
        motorSensors.vibration = 85;
        motorSensors.rpm = 700;
    }
}