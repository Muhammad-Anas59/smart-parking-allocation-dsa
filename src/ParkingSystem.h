#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H
#include "AllocationEngine.h"
class ParkingSystem {
public:
    Zone zones[3];
    int totalZones;
    AllocationEngine* engine;

    ParkingSystem();
    void initializeSystem();
    void processRequest(ParkingRequest& request);
};

#endif
