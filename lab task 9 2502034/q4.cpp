
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Medicine {
public:
    string name;
    int medicineID;
    int expiryDate;
    Medicine *left, *right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};

class MinHeap {
private:
    Medicine* root;
    Medicine* nodes[100];
    int size;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (nodes[i]->expiryDate < nodes[parent]->expiryDate) {
                swap(nodes[i]->name, nodes[parent]->name);
                swap(nodes[i]->medicineID, nodes[parent]->medicineID);
                swap(nodes[i]->expiryDate, nodes[parent]->expiryDate);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && nodes[left]->expiryDate < nodes[smallest]->expiryDate)
                smallest = left;

            if (right < size && nodes[right]->expiryDate < nodes[smallest]->expiryDate)
                smallest = right;

            if (smallest != i) {
                swap(nodes[i]->name, nodes[smallest]->name);
                swap(nodes[i]->medicineID, nodes[smallest]->medicineID);
                swap(nodes[i]->expiryDate, nodes[smallest]->expiryDate);
                i = smallest;
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
    MinHeap() {
        size = 0;
        root = NULL;
    }

    void insert(string n, int id, int date) {
        nodes[size] = new Medicine(n, id, date);
        size++;
        heapifyUp(size - 1);
        updateLinks();
    }

    void display() {
        if (root == NULL) return;

        queue<Medicine*> q;
        q.push(root);

        cout << "\nMedicine Heap (Level Order):\n";

        while (!q.empty()) {
            Medicine* temp = q.front();
            q.pop();

            cout << temp->name << " | ID: " << temp->medicineID
                 << " | Expiry Date: " << temp->expiryDate << endl;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    void deleteNearestExpiry() {
        if (size == 0) return;

        cout << "\nDeleted Medicine: " << nodes[0]->name
             << " | Expiry Date: " << nodes[0]->expiryDate << endl;

        delete nodes[0];

        nodes[0] = nodes[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);

        updateLinks();
    }
};

int main() {
    MinHeap h;

    h.insert("Panadol", 401, 20271215);
    h.insert("Brufen", 402, 20261220);
    h.insert("Augmentin", 403, 20281110);
    h.insert("Disprin", 404, 20260515);
    h.insert("Calpol", 405, 20271025);
    h.insert("Flagyl", 406, 20260918);

    h.display();

    h.deleteNearestExpiry();

    cout << "\nUpdated Medicine Heap:";
    h.display();

    return 0;
}

