// sensors.h - Sensor definitions and functions
#ifndef SENSORS_H
#define SENSORS_H

#include "xc.h"

// Sensor threshold values
#define TEMP_WARNING    70    // Temperature warning level
#define TEMP_CRITICAL   85    // Temperature critical level
#define VIB_WARNING     60    // Vibration warning level
#define VIB_CRITICAL    80    // Vibration critical level
#define RPM_MIN         800   // Minimum safe RPM
#define RPM_MAX         3200  // Maximum safe RPM

// Sensor data structure
typedef struct {
    unsigned int temperature;  // Motor temperature
    unsigned int vibration;    // Motor vibration
    unsigned int rpm;          // Motor speed
} SensorData;

// Global sensor data variable
extern SensorData motorSensors;

// Function declarations
void SENSORS_Init(void);
void SENSORS_Read(void);

// State name strings for display
#define STATE_NAME_0 "HEALTHY"
#define STATE_NAME_1 "DEGRADING"  
#define STATE_NAME_2 "CRITICAL"
#define STATE_NAME_3 "FAULT"

#endif /* SENSORS_H */