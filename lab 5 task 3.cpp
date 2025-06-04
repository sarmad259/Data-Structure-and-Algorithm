#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!isEmpty()) {
            Node* temp = top;
            char val = temp->data;
            top = top->next;
            delete temp;
            return val;
        } else {
            return '\0'; 
        }
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
  
    Stack Redo;
    string Name = "Fariba";

    while (true) {
        cout << "Current Text: " << Name << endl;
        cout << "Type 'undo' for Undo and 'redo' for Redo action: ";

        string action;
        getline(cin, action);

        if (action == "undo") {
            if (!Name.empty()) {
                Redo.push(Name.back());
                Name.pop_back();
            } else {
                cout << "Nothing to undo here" << endl;
            }
        } else if (action == "redo") {
            if (!Redo.isEmpty()) {
                Name += Redo.pop();
            } else {
                cout << "Nothing to redo." << endl;
            }
        }
    }

    return 0;
}
