#include "AllocationEngine.h"
AllocationEngine::AllocationEngine(Zone* z, int count) {
    zones = z;
    totalZones = count;
}

ParkingSlot* AllocationEngine::allocateSlot(ParkingRequest& request) {
    for (int i = 0; i < totalZones; i++) {
        if (zones[i].zoneId == request.vehicle.preferredZone) {
            ParkingSlot* slot = zones[i].findFreeSlot();
            if (slot != nullptr) {
                slot->occupy();
                request.isProcessed = true;
                return slot;
            }
        }
    }
    return nullptr;
}
