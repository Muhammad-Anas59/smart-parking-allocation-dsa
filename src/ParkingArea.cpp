#include "ParkingArea.h"

ParkingArea::ParkingArea() {
    totalSlots = 0;
}

void ParkingArea::addSlot(ParkingSlot slot) {
    slots[totalSlots] = slot;
    totalSlots++;
}

ParkingSlot* ParkingArea::getFreeSlot() {
    for (int i = 0; i < totalSlots; i++) {
        if (slots[i].isFree) {
            return &slots[i];
        }
    }
    return nullptr;
}
