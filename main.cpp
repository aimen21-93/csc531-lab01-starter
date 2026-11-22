
#include <iostream>
#include <limits>
#include "lab01.hpp"

using namespace std;

int main() {
    constexpr int CAP = 8;

    int values[CAP] = {70, 80, 90, 85};
    int size = 4;

    int choice, pos, x;

    cout << "===== CSC-531 LAB 01 =====\n";

    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Exit\n";
        cout << "==========================\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {

            case 1:
                cout << "\nActive Array: ";

                if (size == 0) {
                    cout << "Empty";
                } else {
                    for (int i = 0; i < size; i++) {
                        cout << values[i] << " ";
                    }
                }

                cout << "\nLogical Size: " << size;
                cout << "\nCapacity: " << CAP << "\n";
                break;

            case 2:
                cout << "Enter insertion position: ";

                if (!(cin >> pos)) {
                    cout << "Invalid position input!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter value to insert: ";

                if (!(cin >> x)) {
                    cout << "Invalid value input!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (insertAt(values, size, CAP, pos, x)) {
                    cout << "Element inserted successfully!\n";
                } else {
                    cout << "Insertion failed! Invalid position or array is full.\n";
                }
                break;

            case 3:
                cout << "Enter deletion position: ";

                if (!(cin >> pos)) {
                    cout << "Invalid position input!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                if (deleteAt(values, size, pos)) {
                    cout << "Element deleted successfully!\n";
                } else {
                    cout << "Deletion failed! Invalid position or array is empty.\n";
                }
                break;

            case 4:
                cout << "Exiting program. Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select 1 to 4.\n";
        }
    }

    return 0;
}
