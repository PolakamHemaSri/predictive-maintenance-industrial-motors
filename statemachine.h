// statemachine.h - Motor health state definitions
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "xc.h"

// Motor health states
// Like traffic light for motor health!
typedef enum {
    STATE_HEALTHY   = 0,  // Green  - All good!
    STATE_DEGRADING = 1,  // Yellow - Watch out!
    STATE_CRITICAL  = 2,  // Red    - Act now!
    STATE_FAULT     = 3   // Black  - Emergency!
} MotorState;

// Current motor state variable
extern MotorState currentState;

// Callback function pointer type
// This is from Course 7 - Callbacks!
typedef void (*StateCallback)(MotorState);

// Function declarations
void STATEMACHINE_Init(void);
void STATEMACHINE_Update(void);
void STATEMACHINE_RegisterCallback(StateCallback cb);

#endif /* STATEMACHINE_H */