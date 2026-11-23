
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    int marks;
    Student *left, *right;

    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};

class MaxHeap {
private:
    Student* root;
    Student* nodes[100];
    int size;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (nodes[i]->marks > nodes[parent]->marks) {
                swap(nodes[i]->name, nodes[parent]->name);
                swap(nodes[i]->rollNo, nodes[parent]->rollNo);
                swap(nodes[i]->marks, nodes[parent]->marks);
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

            if (left < size && nodes[left]->marks > nodes[largest]->marks)
                largest = left;

            if (right < size && nodes[right]->marks > nodes[largest]->marks)
                largest = right;

            if (largest != i) {
                swap(nodes[i]->name, nodes[largest]->name);
                swap(nodes[i]->rollNo, nodes[largest]->rollNo);
                swap(nodes[i]->marks, nodes[largest]->marks);
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

    void insert(string n, int r, int m) {
        nodes[size] = new Student(n, r, m);
        size++;
        heapifyUp(size - 1);
        updateLinks();
    }

    void display() {
        if (root == NULL) return;

        queue<Student*> q;
        q.push(root);

        cout << "\nStudent Heap (Level Order):\n";

        while (!q.empty()) {
            Student* temp = q.front();
            q.pop();

            cout << temp->name << " | Roll No: " << temp->rollNo
                 << " | Marks: " << temp->marks << endl;

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    void deleteHighest() {
        if (size == 0) return;

        cout << "\nDeleted Student: " << nodes[0]->name
             << " | Marks: " << nodes[0]->marks << endl;

        delete nodes[0];

        nodes[0] = nodes[size - 1];
        size--;

        heapifyDown(0);
        updateLinks();
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 92);
    h.insert("Sara", 103, 98);
    h.insert("Ayesha", 104, 88);
    h.insert("Usman", 105, 95);
    h.insert("Hassan", 106, 90);

    h.display();

    h.deleteHighest();

    cout << "\nUpdated Heap:";
    h.display();

    return 0;
}

