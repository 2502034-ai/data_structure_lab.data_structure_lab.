
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
public:

    int height(Node* node) {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == NULL)
            return 0;

        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left),
                            height(y->right));

        x->height = 1 + max(height(x->left),
                            height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left),
                            height(x->right));

        y->height = 1 + max(height(y->left),
                            height(y->right));

        return y;
    }

    Node* insert(Node* root, int key) {

        if (root == NULL)
            return new Node(key);

        if (key < root->key)
            root->left = insert(root->left, key);

        else if (key > root->key)
            root->right = insert(root->right, key);

        else
            return root;

        root->height = 1 + max(height(root->left),
                               height(root->right));

        int balance = balanceFactor(root);

        if (balance > 1 && key < root->left->key)
            return rightRotate(root);

        if (balance < -1 && key > root->right->key)
            return leftRotate(root);

        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void display(Node* root, int level = 0) {
        if (root != NULL) {
            display(root->right, level + 1);

            for (int i = 0; i < level; i++)
                cout << "    ";

            cout << root->key << endl;

            display(root->left, level + 1);
        }
    }

    void showBalance(Node* root) {
        if (root != NULL) {
            showBalance(root->left);

            cout << "Token: " << root->key
                 << " Height: " << root->height
                 << " Balance Factor: "
                 << balanceFactor(root) << endl;

            showBalance(root->right);
        }
    }
};

int main() {
    AVLTree avl;
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = avl.insert(root, tokens[i]);
    }

    cout << "In-order Traversal:" << endl;
    avl.inorder(root);

    cout << "\n\nFinal Balanced AVL Tree:" << endl;
    avl.display(root);

    cout << "\nNode Heights and Balance Factors:" << endl;
    avl.showBalance(root);

    return 0;
}

