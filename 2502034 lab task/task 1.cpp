#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* node) {
    if (node != NULL) {
        cout << "Member: " << node->name << endl;

        cout << "Left Child: ";
        if (node->left != NULL)
            cout << node->left->name;
        else
            cout << "None";

        cout << endl;

        cout << "Right Child: ";
        if (node->right != NULL)
            cout << node->right->name;
        else
            cout << "None";

        cout << endl;
        cout << "-------------------" << endl;

        displayTree(node->left);
        displayTree(node->right);
    }
}

int main() {
    Node* root = new Node("HOD");

    root->left = new Node("Academic Coordinator");
    root->right = new Node("Administrative Coordinator");

    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");

    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    cout << "University Department Hierarchy" << endl;

    displayTree(root);

    return 0;
}
