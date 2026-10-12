
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class PatientStack {
private:
    Node* top;

public:
    PatientStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No patient requests!" << endl;
        } else {
            Node* temp = top;
            cout << "Handled Patient Request: "
                 << top->patientID << endl;
            top = top->next;
            delete temp;
        }
    }

    void displayRequests() {
        if (top == NULL) {
            cout << "No remaining requests." << endl;
            return;
        }

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No TOP request." << endl;
        } else {
            cout << "New TOP request: "
                 << top->patientID << endl;
        }
    }

    ~PatientStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    PatientStack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "Patient Requests (Top to Bottom):" << endl;
    hospital.displayRequests();

    cout << endl;
    hospital.pop();

    cout << endl;
    hospital.displayTop();

    cout << endl;
    cout << "Remaining Patient Requests:" << endl;
    hospital.displayRequests();

    return 0;
}
