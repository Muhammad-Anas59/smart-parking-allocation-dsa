#include "Zone.h"

Zone::Zone() {
    zoneId = -1;
    totalAreas = 0;
}

Zone::Zone(int id) {
    zoneId = id;
    totalAreas = 0;
}

ParkingSlot* Zone::findFreeSlot() {
    for (int i = 0; i < totalAreas; i++) {
        ParkingSlot* slot = areas[i].getFreeSlot();
        if (slot != nullptr) {
            return slot;
        }
    }
    return nullptr;
}
