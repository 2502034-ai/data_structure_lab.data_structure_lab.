
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Patient {
public:
    string name;
    int patientID;
    int priority;
    Patient *left, *right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};

class MaxHeap {
private:
    Patient* root;
    Patient* nodes[100];
    int size;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (nodes[i]->priority > nodes[parent]->priority) {
                swap(nodes[i]->name, nodes[parent]->name);
                swap(nodes[i]->patientID, nodes[parent]->patientID);
                swap(nodes[i]->priority, nodes[parent]->priority);
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

            if (left < size && nodes[left]->priority > nodes[largest]->priority)
                largest = left;

            if (right < size && nodes[right]->priority > nodes[largest]->priority)
                largest = right;

            if (largest != i) {
                swap(nodes[i]->name, nodes[largest]->name);
                swap(nodes[i]->patientID, nodes[largest]->patientID);
                swap(nodes[i]->priority, nodes[largest]->priority);
                i = largest;
            } else {
                break;
            }
        }
    }

    void updateLinks() {
        for (int i = 0; i < size; i++) {
            nodes[i]->left = (2 * i + 1 < size) ? nodes[2 * i + 1] : NULL;
            nodes[i]->right = (2 * i + 2 < size) ? nodes[2 * i + 2] : NULL;
        }
        root = size > 0 ? nodes[0] : NULL;
    }

public:
    MaxHeap() {
        size = 0;
        root = NULL;
    }

    void insert(string n, int id, int p) {
        nodes[size] = new Patient(n, id, p);
        size++;
        heapifyUp(size - 1);
        updateLinks();
    }

    void display() {
        if (root == NULL) return;

        queue<Patient*> q;
        q.push(root);

        while (!q.empty()) {
            Patient* temp = q.front();
            q.pop();

            cout << temp->name << " | ID: " << temp->patientID
                 << " | Priority: " << temp->priority << endl;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    void treatPatient() {
        if (size == 0) return;

        cout << "\nPatient Treated: " << nodes[0]->name
             << " | Priority: " << nodes[0]->priority << endl;

        delete nodes[0];

        nodes[0] = nodes[size - 1];
        size--;

        heapifyDown(0);
        updateLinks();
    }

    void nextPatient() {
        if (root != NULL) {
            cout << "\nNext Patient: " << root->name
                 << " | ID: " << root->patientID
                 << " | Priority: " << root->priority << endl;
        }
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 201, 5);
    h.insert("Ahmed", 202, 9);
    h.insert("Sara", 203, 7);
    h.insert("Ayesha", 204, 10);
    h.insert("Usman", 205, 6);
    h.insert("Hassan", 206, 8);

    cout << "Hospital Patient Heap:\n";
    h.display();

    cout << "\nHighest Priority Patient:";
    h.nextPatient();

    h.treatPatient();

    cout << "\nUpdated Patient Heap:\n";
    h.display();

    h.nextPatient();

    return 0;
}

