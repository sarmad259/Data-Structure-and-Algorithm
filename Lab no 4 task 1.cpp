#include <iostream>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class Dlinkedlist {
public:
    Node* head;
    int length;

    Dlinkedlist() {
        head = NULL;
        length = 0;
    }

    void insert(int pos, string val) {
        if (pos < 1 || pos > (length + 1)) {
            cout << "Invalid position" << endl;
            return;
        } else if (pos == 1) {
            Node* temp = new Node(val);
            if (isEmpty()) {
                temp->next = head;
                head = temp;
            } else {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
        } else {
            Node* temp = new Node(val);
            Node* curr = head;
            for (int i = 1; i < (pos - 1); i++) {
                curr = curr->next;
            }
            temp->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = temp;
            }
            curr->next = temp;
            temp->prev = curr;
        }
        length++;
    }

    void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return length == 0;
    }
    
};
int main() {
    Dlinkedlist D;
    int choice;
    int pos;
    string val;

    while (true) {
        cout << "Welcome to My Menu. Enter the number for the following options:\n"
             << "1. Add Task\n"
             << "2. Mark Complete\n"
             << "3. Remove Completed Task\n"
             << "4. Display Task\n"
             << "5. Exit\n";
             
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the position where you want to add a task: ";
            cin >> pos;
            cout << "Enter the text of the task: ";
            cin >> val;
            D.insert(pos, val);
        } else if (choice == 2) {
            
        } else if (choice == 3) {
            
        } else if (choice == 4) {
            cout << "Tasks:\n";
            D.print();
        } else if (choice == 5) {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}