#include "ParkingRequest.h"

ParkingRequest::ParkingRequest() {
    isProcessed = false;
}

ParkingRequest::ParkingRequest(Vehicle v) {
    vehicle = v;
    isProcessed = false;
}
