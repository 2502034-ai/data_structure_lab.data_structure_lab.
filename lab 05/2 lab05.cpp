#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

class Game {
private:
    Node* head;

public:
    Game() {
        head = NULL;
    }

    void addPlayer(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* current = head;

            while (current->next != head) {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = head;
        }
    }

    void displayTurns() {
        if (head == NULL) {
            return;
        }

        Node* current = head;

        cout << "Player Turns:" << endl;

        do {
            cout << current->player << endl;
            current = current->next;
        } while (current != head);

        cout << "\nAfter the last player, turn returns to: "
             << current->player << endl;
    }
};

int main() {
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Usman");
    game.addPlayer("Hamza");
    game.addPlayer("Bilal");

    game.displayTurns();

    return 0;
}

