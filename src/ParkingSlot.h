#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

class ParkingSlot {
public:
    int slotId;
    int zoneId;
    bool isFree;

    ParkingSlot();
    ParkingSlot(int sId, int zId);

    void occupy();
    void release();
};

#endif
