#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H
#include "ParkingSlot.h"

class RollbackManager {
public:
    static void rollback(ParkingSlot* slot);
};

#endif
