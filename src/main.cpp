/*
 Smart Parking Management System
 Graphical Console-Based User Interface

 - Displays parking zones and slots graphically using symbols
 - O = Free Slot, X = Occupied Slot
 - Interactive menu-driven interface
 - Backend implemented using OOP (Zone, ParkingArea, ParkingSlot)
*/

#include <iostream>
#include "Zone.h"

using namespace std;

// Graphical display function
void displayUI(Zone zones[], int NUM_ZONES)
{
    system("cls"); // use "clear" on Linux/Mac

    cout << "========================================\n";
    cout << "        SMART PARKING SYSTEM UI          \n";
    cout << "========================================\n\n";

    for (int z = 0; z < NUM_ZONES; z++) {
        cout << "ZONE " << z + 1 << "\n";

        for (int a = 0; a < zones[z].totalAreas; a++) {
            for (int s = 0; s < zones[z].areas[a].totalSlots; s++) {
                cout << "[ "
                     << (zones[z].areas[a].slots[s].isFree ? 'O' : 'X')
                     << " ] ";
            }
        }
        cout << "\n\n";
    }

    cout << "O = Free Slot | X = Occupied Slot\n\n";
}

int main() {
    const int NUM_ZONES = 2;
    Zone zones[NUM_ZONES] = { Zone(1), Zone(2) };

    // SAME SLOT & ZONE SETUP AS YOUR CODE
    for (int z = 0; z < NUM_ZONES; z++) {
        ParkingArea area;
        for (int s = 101; s <= 110; s++) {
            area.addSlot(ParkingSlot(s + z * 100, z + 1));
        }
        zones[z].areas[zones[z].totalAreas++] = area;
    }

    int choice;
    bool running = true;

    while (running) {

        displayUI(zones, NUM_ZONES);

        cout << "1. Allocate Parking Slot\n";
        cout << "2. Release Parking Slot\n";
        cout << "3. View Parking Status (Detailed)\n";
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
                cin.get(); cin.get();
                break;
            }

            ParkingSlot* slot = zones[zoneChoice - 1].findFreeSlot();
            if (slot != nullptr) {
                slot->occupy();
                cout << "Slot allocated successfully. Zone: "
                     << zoneChoice << ", Slot ID: "
                     << slot->slotId << endl;
            } else {
                cout << "No free parking slot in this zone.\n";
            }
            cin.get(); cin.get();
            break;
        }

        case 2: {
            int id, zoneChoice;
            cout << "Select Zone (1-" << NUM_ZONES << "): ";
            cin >> zoneChoice;
            cout << "Enter Slot ID (3 Digits) to release: ";
            cin >> id;

            if (zoneChoice < 1 || zoneChoice > NUM_ZONES) {
                cout << "Invalid zone.\n";
                cin.get(); cin.get();
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
            cin.get(); cin.get();
            break;
        }

        case 3: {
            cout << "\n--- Detailed Parking Status ---\n";
            for (int z = 0; z < NUM_ZONES; z++) {
                cout << "Zone " << z + 1 << ":\n";
                for (int a = 0; a < zones[z].totalAreas; a++) {
                    for (int s = 0; s < zones[z].areas[a].totalSlots; s++) {
                        cout << "Slot "
                             << zones[z].areas[a].slots[s].slotId
                             << " - "
                             << (zones[z].areas[a].slots[s].isFree
                                 ? "FREE" : "OCCUPIED")
                             << endl;
                    }
                }
            }
            cin.get(); cin.get();
            break;
        }

        case 4:
            running = false;
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            cin.get(); cin.get();
        }
    }

    return 0;
}
