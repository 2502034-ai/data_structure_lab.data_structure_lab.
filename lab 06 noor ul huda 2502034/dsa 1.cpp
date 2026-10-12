

#include <iostream>
#include <string>
using namespace std;

class BrowserStack {
private:
    string pages[10];
    int top;

public:
    BrowserStack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
        } else {
            pages[++top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No browsing history!" << endl;
        } else {
            cout << "Back button pressed. Removed: "
                 << pages[top] << endl;
            top--;
        }
    }

    void displayHistory() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }

        cout << "Browsing History (Top to Bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current page." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }
};

int main() {
    BrowserStack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    browser.displayHistory();

    cout << endl;
    browser.pop();

    browser.displayTop();

    cout << endl;
    cout << "Remaining Browsing History:" << endl;
    browser.displayHistory();

    return 0;
}
