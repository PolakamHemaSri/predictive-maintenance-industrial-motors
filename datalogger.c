#include "datalogger.h"
#include "statemachine.h"

DataLog motorLog;
static DataNode nodePool[MAX_READINGS];
static unsigned int poolIndex = 0;

void DATALOGGER_Init(void) {
    motorLog.head = 0;
    motorLog.tail = 0;
    motorLog.count = 0;
    poolIndex = 0;
}

void DATALOGGER_Save(void) {
    DataNode* newNode;
    
    if(poolIndex >= MAX_READINGS) {
        poolIndex = 0;
    }
    
    newNode = &nodePool[poolIndex++];
    newNode->data = motorSensors;
    newNode->stateAtTime = currentState;
    newNode->next = 0;
    
    if(motorLog.head == 0) {
        motorLog.head = newNode;
        motorLog.tail = newNode;
    }
    else {
        motorLog.tail->next = newNode;
        motorLog.tail = newNode;
    }
    
    if(motorLog.count < MAX_READINGS) {
        motorLog.count++;
    }
}

void DATALOGGER_Print(void) {
    DataNode* current = motorLog.head;
    while(current != 0) {
        current = current->next;
    }
}