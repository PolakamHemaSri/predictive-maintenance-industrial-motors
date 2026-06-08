#include "statemachine.h"
#include "sensors.h"

MotorState currentState;
static StateCallback stateChangeCallback = 0;

void STATEMACHINE_Init(void) {
    currentState = STATE_HEALTHY;
    stateChangeCallback = 0;
}

void STATEMACHINE_RegisterCallback(StateCallback cb) {
    stateChangeCallback = cb;
}

void STATEMACHINE_Update(void) {
    MotorState newState;
    
    if(motorSensors.temperature >= 85 ||
       motorSensors.vibration >= 80 ||
       motorSensors.rpm < 800) {
        newState = STATE_FAULT;
    }
    else if(motorSensors.temperature >= 70 ||
            motorSensors.vibration >= 60) {
        newState = STATE_CRITICAL;
    }
    else if(motorSensors.temperature >= 60 ||
            motorSensors.vibration >= 45) {
        newState = STATE_DEGRADING;
    }
    else {
        newState = STATE_HEALTHY;
    }
    
    if(newState != currentState) {
        currentState = newState;
        if(stateChangeCallback != 0) {
            stateChangeCallback(currentState);
        }
    }
}