#ifndef PARKINGREQUEST_H
#define PARKINGREQUEST_H

#include "Vehicle.h"

class ParkingRequest {
public:
    Vehicle vehicle;
    bool isProcessed;

    ParkingRequest();
    ParkingRequest(Vehicle v);
};

#endif
