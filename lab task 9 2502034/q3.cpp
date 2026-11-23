
#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    float amount;
    Order *left, *right;

    Order(int id, string name, float a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = NULL;
    }
};

class MaxHeap {
private:
    Order* nodes[100];
    int size;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (nodes[i]->amount > nodes[parent]->amount) {
                swap(nodes[i]->orderID, nodes[parent]->orderID);
                swap(nodes[i]->customerName, nodes[parent]->customerName);
                swap(nodes[i]->amount, nodes[parent]->amount);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && nodes[left]->amount > nodes[largest]->amount)
                largest = left;

            if (right < size && nodes[right]->amount > nodes[largest]->amount)
                largest = right;

            if (largest != i) {
                swap(nodes[i]->orderID, nodes[largest]->orderID);
                swap(nodes[i]->customerName, nodes[largest]->customerName);
                swap(nodes[i]->amount, nodes[largest]->amount);
                i = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int id, string name, float amount) {
        nodes[size] = new Order(id, name, amount);
        size++;
        heapifyUp(size - 1);
    }

    void heapSort() {
        float sorted[100];
        int count = size;

        for (int i = 0; i < count; i++) {
            sorted[i] = nodes[0]->amount;

            delete nodes[0];

            nodes[0] = nodes[size - 1];
            size--;

            if (size > 0)
                heapifyDown(0);
        }

        cout << "\nOrder Amounts in Ascending Order:\n";

        for (int i = count - 1; i >= 0; i--) {
            cout << sorted[i] << endl;
        }
    }
};

int main() {
    MaxHeap h;

    h.insert(301, "Ali", 5000);
    h.insert(302, "Ahmed", 2500);
    h.insert(303, "Sara", 8000);
    h.insert(304, "Ayesha", 1500);
    h.insert(305, "Usman", 6000);
    h.insert(306, "Hassan", 3500);

    h.heapSort();

    return 0;
}

