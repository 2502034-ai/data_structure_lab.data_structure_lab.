
#include <iostream>
using namespace std;

#define SIZE 5

class Patient {
public:
    int id;
    int priority;
};

class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(int id, int priority) {
        if (count == SIZE) {
            cout << "Queue is full! Cannot add more patients.\n";
            return;
        }

        patients[count].id = id;
        patients[count].priority = priority;
        count++;

        cout << "Patient P" << id << " added successfully.\n";
    }

    void treatPatient() {
        if (count == 0) {
            cout << "No patients waiting for treatment.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highest].priority) {
                highest = i;
            }
        }

        cout << "Treating Patient P" << patients[highest].id
             << " with priority "
             << patients[highest].priority << ".\n";

        for (int i = highest; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";

        for (int i = 0; i < count; i++) {
            cout << "Patient P" << patients[i].id
                 << " | Priority: "
                 << patients[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue q;
    int choice, id, priority;

    do {
        cout << "\n===== Hospital Emergency Department =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient ID: P";
            cin >> id;
            cout << "Enter priority (1 = highest): ";
            cin >> priority;
            q.enqueue(id, priority);
            break;

        case 2:
            q.treatPatient();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
