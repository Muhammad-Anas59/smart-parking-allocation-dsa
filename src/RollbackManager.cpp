#include "RollbackManager.h"

void RollbackManager::rollback(ParkingSlot* slot) {
    if (slot != nullptr) {
        slot->release();
    }
}
