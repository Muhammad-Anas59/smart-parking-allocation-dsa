#include <iostream>
#include "Zone.h"

using namespace std;

int main() {
    const int NUM_ZONES = 2;
    Zone zones[NUM_ZONES] = { Zone(1), Zone(2) };

    for (int z = 0; z < NUM_ZONES; z++) {
        ParkingArea area;
        for (int s = 101; s <= 110; s++) {  
            area.addSlot(ParkingSlot(s + z*100, z + 1)); 
        }
        zones[z].areas[zones[z].totalAreas++] = area;
    }

    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== Smart Parking Management System =====\n";
        cout << "1. Allocate Parking Slot\n";
        cout << "2. Release Parking Slot\n";
        cout << "3. View Parking Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int zoneChoice;
            cout << "Select Zone (1-" << NUM_ZONES << "): ";
            cin >> zoneChoice;
            if (zoneChoice < 1 || zoneChoice > NUM_ZONES) {
                cout << "Invalid zone.\n";
                break;
            }

            ParkingSlot* slot = zones[zoneChoice - 1].findFreeSlot();
            if (slot != nullptr) {
                slot->occupy();
                cout << "Slot allocated successfully. Zone: " << zoneChoice
                     << ", Slot ID: " << slot->slotId << endl;
            } else {
                cout << "No free parking slot in this zone.\n";
            }
            break;
        }

        case 2: {
            int id, zoneChoice;
            cout << "Select Zone (1-" << NUM_ZONES << "): ";
            cin >> zoneChoice;
            cout << "Enter Slot ID(3 Digits) to release: ";
            cin >> id;

            if (zoneChoice < 1 || zoneChoice > NUM_ZONES) {
                cout << "Invalid zone.\n";
                break;
            }

            bool found = false;
            for (int i = 0; i < zones[zoneChoice - 1].totalAreas; i++) {
                for (int j = 0; j < zones[zoneChoice - 1].areas[i].totalSlots; j++) {
                    if (zones[zoneChoice - 1].areas[i].slots[j].slotId == id) {
                        zones[zoneChoice - 1].areas[i].slots[j].release();
                        cout << "Slot " << id << " released successfully.\n";
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                cout << "Slot not found.\n";
            }
            break;
        }

        case 3: {
            cout << "\n--- Parking Status ---\n";
            for (int z = 0; z < NUM_ZONES; z++) {
                cout << "Zone " << z + 1 << ":\n";
                for (int a = 0; a < zones[z].totalAreas; a++) {
                    cout << "  Area " << a + 1 << " Slots:\n";
                    for (int s = 0; s < zones[z].areas[a].totalSlots; s++) {
                        cout << "    Slot " << zones[z].areas[a].slots[s].slotId
                             << " - " << (zones[z].areas[a].slots[s].isFree ? "FREE" : "OCCUPIED") << endl;
                    }
                }
            }
            break;
        }

        case 4:
            running = false;
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
