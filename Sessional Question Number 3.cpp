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

void reverseKNodes(int k) {
    if (head == nullptr || k <= 1) {
        return; 
    }

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* GS = head; 
    Node* Previous_Grp = nullptr;
    bool reverse = true;

    while (current != nullptr) {
        Node* End_Grp = current; 
        int count = 0;

        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (reverse) {
            if (Previous_Grp != nullptr) {
                Previous_Grp->next = prev;
            } else {
                head = prev;
            }
            GS->next = current;
        } else {
            Previous_Grp = GS;
        }

        
        GS = End_Grp;
        reverse = !reverse;
    }
}


};

int main() {
    LinkedList L;

    
    L.insert(0, 1);
    L.insert(1, 2);
    L.insert(2, 3);
    L.insert(3, 4);
    L.insert(4, 5);
    L.insert(5, 6);
    L.insert(6, 7);
    L.insert(7, 8);
    L.insert(8, 9);

    cout << "Original List: ";
    L.print();

    int k = 3;
    L.reverseKNodes(k);

    cout << "Reversed List with alternate groups of " << k << " nodes: ";
    L.print();

    return 0;
}

