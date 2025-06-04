#include<iostream>
using namespace std;

class Node {  
public:
    int val;
    Node* next;  

    Node(int val) {
        this->val = val;
        this->next = nullptr; 
    }
};

class LinkedList {
public:
    int length;
    Node* head;

    LinkedList() {
        length = 0;
        head = nullptr;
    }

    void insert(int pos, int val) {
        if (pos < 0) {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0) {
            Node* newnode = new Node(val);
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* current = head;
        int count = 0;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Invalid Position" << endl;
            return;
        }

        Node* newnode = new Node(val);
        newnode->next = current->next;
        current->next = newnode;
    }

    void deleteNode(int pos) {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (pos < 0) {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int count = 0;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Position does not exist" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList L;

    L.insert(0, 1);
    L.insert(1, 2);
    L.insert(2, 3);
    L.insert(1, 4);
    L.print();

    L.deleteNode(1);
    L.print();

    return 0;
}
