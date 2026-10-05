#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = this;
    }
};

class Playlist {
private:
    Node* head;

public:
    Playlist() {
        head = NULL;
    }

    void addSong(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;

            while (current->next != head) {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = head;
        }
    }

    void displayOnce() {
        Node* current = head;

        cout << "Playlist:" << endl;

        do {
            cout << current->song << endl;
            current = current->next;
        } while (current != head);
    }

    void playTwoRounds() {
        Node* current = head;

        cout << "\nPlaying Playlist for 2 Rounds:" << endl;

        for (int i = 0; i < 10; i++) {
            cout << current->song << endl;
            current = current->next;
        }
    }
};

int main() {
    Playlist playlist;

    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    playlist.displayOnce();
    playlist.playTwoRounds();

    return 0;
}

