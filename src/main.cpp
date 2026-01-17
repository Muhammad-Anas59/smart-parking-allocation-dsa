#include <iostream>
#include "Zone.h"

int main() {
    Zone z1(1);

    ParkingArea area;
    area.addSlot(ParkingSlot(101, 1));
    area.addSlot(ParkingSlot(102, 1));

    z1.areas[z1.totalAreas++] = area;

    ParkingSlot* s = z1.findFreeSlot();
    if (s != nullptr) {
        std::cout << "Slot allocated: " << s->slotId << std::endl;
        s->occupy();
    }

    // Pause the console before exit
    std::cout << "Press Enter to exit...";
    std::cin.get();  // Waits for user input

    return 0;
}
