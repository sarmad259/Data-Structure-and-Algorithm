#include <iostream>
using namespace std;

class Customer {
public:
    string name;
    Customer* next;
    Customer(string name) {
        this->name = name;
        next = nullptr;
    }
};

class Queue {
public:
    Customer* front;
    Customer* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string name) {
        Customer* newCustomer = new Customer(name);
        if (isEmpty()) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }

    string getFront() {
        if (!isEmpty()) {
            return front->name;
        } else {
            return "Queue is empty.";
        }
    }
    ~Queue() {
     
        while (!isEmpty()) {
            dequeue();
        }
    }

};

int main() {
    Queue Ticket;
    Queue Roller;
    Queue Motion;
    Queue RoundWheel;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter customer in the ticket purchase queue\n";
        cout << "2. Sell a ticket\n";
        cout << "3. Process all queues\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string customerName;
                cout << "Enter Customer Name: ";
                cin >> customerName;
                Ticket.enqueue(customerName);
                break;
            }
            case 2: {
                if (!Ticket.isEmpty()) {
                    string customerName = Ticket.getFront();
                    Ticket.dequeue();
                    cout << "Ticket has been sold to " << customerName << endl;
                    cout << "Adding " << customerName << " to an attraction queue." << endl;

                    int attractionChoice;
                    cout << "Select an attraction to join (1 - Roller Coaster, 2 - Motion Ride, 3 - Round Wheel): ";
                    cin >> attractionChoice;

                    switch (attractionChoice) {
                        case 1:
                            Roller.enqueue(customerName);
                            break;
                        case 2:
                            Motion.enqueue(customerName);
                            break;
                        case 3:
                            RoundWheel.enqueue(customerName);
                            break;
                        default:
                            cout << "Invalid attraction choice." << endl;
                            break;
                    }
                } else {
                    cout << "No customers in the ticket purchase queue." << endl;
                }
                break;
            }
            case 3:
                cout << "Processing all queues..." << endl;
                while (!Roller.isEmpty() || !Motion.isEmpty() || !RoundWheel.isEmpty()) {
                    if (!Roller.isEmpty()) {
                        string visitorName = Roller.getFront();
                        Roller.dequeue();
                        cout << "Visitor " << visitorName << " enjoying the Roller Coaster." << endl;
                    }
                    if (!Motion.isEmpty()) {
                        string visitorName = Motion.getFront();
                        Motion.dequeue();
                        cout << "Visitor " << visitorName << " enjoying the Motion Ride." << endl;
                    }
                    if (!RoundWheel.isEmpty()) {
                        string visitorName = RoundWheel.getFront();
                        RoundWheel.dequeue();
                        cout << "Visitor " << visitorName << " enjoying the Round Wheel." << endl;
                    }
                }
                cout << "All queues processed." << endl;
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
