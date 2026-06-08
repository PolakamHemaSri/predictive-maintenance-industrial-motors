// datalogger.h - Data logging using Linked List
#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "xc.h"
#include "sensors.h"

// Maximum readings to store
#define MAX_READINGS 10

// Linked List Node structure
// Each node = one motor reading!
typedef struct DataNode {
    SensorData data;         // Sensor reading
    unsigned int stateAtTime; // Motor state
    struct DataNode* next;   // Points to next node
} DataNode;

// Linked List structure
typedef struct {
    DataNode* head;    // First reading
    DataNode* tail;    // Latest reading
    unsigned int count; // Total readings stored
} DataLog;

// Global data log
extern DataLog motorLog;

// Function declarations
void DATALOGGER_Init(void);
void DATALOGGER_Save(void);
void DATALOGGER_Print(void);

#endif /* DATALOGGER_H */
