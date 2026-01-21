#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H

#include "Zone.h"
#include "ParkingRequest.h"

class AllocationEngine {
public:
    Zone* zones;
    int totalZones;

    AllocationEngine(Zone* z, int count);
    ParkingSlot* allocateSlot(ParkingRequest& request);
};

#endif
