#include "Vehicle.h"

Vehicle::Vehicle() {
    vehicleId = -1;
    preferredZone = -1;
}

Vehicle::Vehicle(int id, int zone) {
    vehicleId = id;
    preferredZone = zone;
}
