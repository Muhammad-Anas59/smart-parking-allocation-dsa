#ifndef ZONE_H
#define ZONE_H

#include "ParkingArea.h"

class Zone {
public:
    int zoneId;
    ParkingArea areas[5];
    int totalAreas;

    Zone();
    Zone(int id);

    ParkingSlot* findFreeSlot();
};

#endif
