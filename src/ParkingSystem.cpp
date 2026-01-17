#include "ParkingSlot.h"

ParkingSlot::ParkingSlot() {
    slotId = -1;
    zoneId = -1;
    isFree = true;
}

ParkingSlot::ParkingSlot(int sId, int zId) {
    slotId = sId;
    zoneId = zId;
    isFree = true;
}

void ParkingSlot::occupy() {
    isFree = false;
}

void ParkingSlot::release() {
    isFree = true;
}
