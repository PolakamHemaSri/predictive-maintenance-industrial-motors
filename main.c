// ============================================
// Predictive Maintenance System
// Device: dsPIC33EP256MC506
// Author: HemaSriPolakam
// Description: Monitors motor health using
//              temperature, vibration & RPM
// ============================================
#include "xc.h"
#include "sensors.h"
#include "statemachine.h"
#include "datalogger.h"
// Configuration bits - tells chip how to start
#pragma config FNOSC = FRC
#pragma config IESO = OFF
// Main function - program starts here
int main(void) {
        // Initialize all systems
    SENSORS_Init();
    STATEMACHINE_Init();
    DATALOGGER_Init();
        // Run forever - like a security guard on duty!
    while(1) {
    // Step 1: Read all sensor values
    SENSORS_Read();
    
    // Step 2: Update motor health state
    STATEMACHINE_Update();
    
    // Step 3: Save data to history
    DATALOGGER_Save();
    
    // Step 4: Print current readings
    if(currentState == STATE_HEALTHY)
        __builtin_software_breakpoint();
    if(currentState == STATE_DEGRADING)
        __builtin_software_breakpoint();
    if(currentState == STATE_CRITICAL)
        __builtin_software_breakpoint();
    if(currentState == STATE_FAULT)
        __builtin_software_breakpoint();
}
    return 0;
}