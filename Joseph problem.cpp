#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Circular {
public:
    Node* head;
    int length;

    Circular() {
        length = 0;
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        length++;
    }

    void display() {
        if (!head) {
            return;
        }

        Node* current = head;
        do {
            cout <<"Remaining Value is "<< current->value ;
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void josephus(int n) {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* cur = head;
        Node* prev = nullptr;

        while (length > 1) {
            for (int i = 1; i < n; i++) {
                prev = cur;
                cur = cur->next;
            }

            prev->next = cur->next;
            Node* temp = cur;
            cur = cur->next;
            delete temp;
            length--;
        }

        head = cur;
    }
};

int main() {
    int m, n;
    Circular C;
    cout << "Welcome to Josephus Problem" << endl;
    cout << "Enter the number of people you want to add to the list: ";
    cin >> m;

    for (int i = 1; i <= m; i++) {
        C.insert(i);
    }

    cout << "Enter the number of steps to skip: ";
    cin >> n;

    C.josephus(n);

    cout << "The survivor is: ";
    C.display();

    return 0;
}
