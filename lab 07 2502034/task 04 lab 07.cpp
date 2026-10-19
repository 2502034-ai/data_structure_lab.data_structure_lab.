
#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! No space available.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        arr[front] = id;
        count++;

        cout << "Request " << id << " inserted at front.\n";
    }

    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! No space available.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = id;
        count++;

        cout << "Request " << id << " inserted at rear.\n";
    }

    void deleteFront() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }

        cout << "Request " << arr[front]
             << " removed from front.\n";

        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }

    void deleteRear() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }

        cout << "Request " << arr[rear]
             << " removed from rear.\n";

        if (count == 1) {
            front = 0;
            rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Requests from front to rear: ";

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, id;

    do {
        cout << "\n===== Train Station Passenger Management =====\n";
        cout << "1. Insert Request at Front\n";
        cout << "2. Insert Request at Rear\n";
        cout << "3. Remove Request from Front\n";
        cout << "4. Remove Request from Rear\n";
        cout << "5. Display All Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger request ID: ";
            cin >> id;
            d.insertFront(id);
            break;

        case 2:
            cout << "Enter passenger request ID: ";
            cin >> id;
            d.insertRear(id);
            break;

        case 3:
            d.deleteFront();
            break;

        case 4:
            d.deleteRear();
            break;

        case 5:
            d.display();
            break;

        case 6:
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
