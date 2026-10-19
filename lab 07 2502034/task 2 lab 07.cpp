
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int packets[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int id) {
        if (count == SIZE) {
            cout << "Queue Overflow! Buffer is full.\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        packets[rear] = id;
        count++;

        cout << "Packet " << id << " added to the queue.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow! No packets available.\n";
            return;
        }

        cout << "Packet " << packets[front]
             << " transmitted successfully.\n";

        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No packets waiting for transmission.\n";
            return;
        }

        cout << "Packets waiting for transmission: ";

        for (int i = 0; i < count; i++) {
            cout << packets[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, id;

    do {
        cout << "\n===== Network Packet Management =====\n";
        cout << "1. Insert Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Waiting Packets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter packet ID: ";
            cin >> id;
            q.enqueue(id);
            break;

        case 2:
            q.dequeue();
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
