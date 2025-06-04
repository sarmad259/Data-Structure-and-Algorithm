#include <iostream>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;
    bool completed; 

    Node(string val) {
        this->val = val;
        next = NULL;
        prev = NULL;
        completed = false;
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

   
   
    void mark(int pos, bool check) {
        Node* curr = head;
        int position = 1;

        while (curr != NULL && position < pos) {
            curr = curr->next;
            position++;
        }

        if (curr != NULL) {
            curr->completed = check;
            cout << "Task at position " << pos << " is marked as " << (check ? "completed" : "not completed") << endl;
            cout<<"The task at " << pos << " is competed"<<endl;
        } else {
            cout << "Invalid position" << endl;
        }
    }
      void print() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->val << " "<<endl;
            curr = curr->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return length == 0;
    }
void removeCompleted() {
    Node* curr = head;
    while (curr != NULL) {
        Node* N = curr->next;
        if (curr->completed) {
            
                if (curr->prev != NULL) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                }
                delete curr;
                length--;
        }
        curr = N;
    }
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
            cout << "Enter The Position: ";
            cin >> pos;
            cin.ignore();
            cout << "Enter the text of the task: ";
            getline(cin, val);
            D.insert(pos, val);
        } else if (choice == 2) {
            cout << "Enter the pos of the task ya wanna mark as completed(1 to " << D.length << "): ";
            cin >> pos;
            bool isCompleted;
            cout << "Is it completed ?1 for completed and 2 for incomplete ";
            cin >> isCompleted;
            D.mark(pos, isCompleted);
        } else if (choice == 3) {
           D.removeCompleted();
        } else if (choice == 4) {
            cout << "Tasks:\n";
            D.print();
        } else if (choice == 5) {
            cout << "Boom!\n";
            break;
        } else {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
