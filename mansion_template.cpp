#include<iostream>
using namespace std;

class Node {
public:
    string val;
    Node *next;

    Node(string val) {
        this->val = val;
        next = NULL;
    }
};

class Stack {
public:
    Node *top;

    Stack() {
        top = NULL;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(string val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return "";
        }
        Node *temp = top;
        string val = temp->val;
        top = top->next;
        delete temp;
        return val;
    }
};

class Queue {
    int front;
    int rear;
    int size;
    string *arr;
    int length;
public:
    Queue(int size) {
        front = 0;
        rear = -1;
        this->size = size;
        arr = new string[size];
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == size;
    }

    void enqueue(string val) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        length++;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return "";
        }
        string val = arr[front];
        front = (front + 1) % size;
        length--;
        return val;
    }

    string getFront() {
        return arr[front];
    }
};

int main() {
    int choice;
    int choice2;
    // Set up the stack for encounters
    Stack encounters;
    string ch;
    Queue mansionQueue(6);
    mansionQueue.enqueue("The Gateway to Darkness");
    mansionQueue.enqueue("The Creeping Corridor");
    mansionQueue.enqueue("The Abandoned Lounge");
    mansionQueue.enqueue("The Haunted Gallery");
    mansionQueue.enqueue("The Shadowed Library");
    mansionQueue.enqueue("The Broken Window");

    cout << "Start exploring the mansion? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
    string places[6];
    if (choice == 1) {
        // Write the rest of the logic to control the mansion exploration
		
        
            cout<<"Do ya saw anythings? "<< endl;
            cout<<"1. Yes" << endl;
            cout << "2. No" << endl;
            cin>>choice2;
            if(choice2==1)
            
                
            cout << "Write what you saw at The Gateway to Darkness" <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();

            cout << "Write what you saw at The Creeping Corridor" <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();
            
            cout << "Write what you saw at The Abandoned Lounge " <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();
            
            cout << "Write what you saw at The Haunted Gallery " <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();
            
            cout << "Write what you saw at The Shadowed Library " <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();           
            
            cout << "Write what you saw at The Broken Window" <<endl;
            getline(cin, ch);
            encounters.push(ch);
            cin.ignore();
            
        cout<<"Yay! You Escaped Unknown King Location(Dark Soul Fans)"<<endl;
        for (int i = 0; i <6; i++)
        {
            cout<<"So you encountered :"<<endl;
            cout<<encounters.pop()<<"    at :  "<<mansionQueue.dequeue()<<endl;

        }
    } else {
        cout << "See you next time" << endl;
        return 0;
    }
}
