#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include "ParkingSlot.h"

class ParkingArea {
public:
    ParkingSlot slots[10];
    int totalSlots;

    ParkingArea();

    void addSlot(ParkingSlot slot);
    ParkingSlot* getFreeSlot();
};

#endif
