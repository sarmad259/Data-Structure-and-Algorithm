#include <iostream>
using namespace std;

class Doc {
public:
    int max_seats;
    string* queue;
    int front;
    int rear;
    int size;

    Doc(int max_seats) : max_seats(max_seats) {
        queue = new string[max_seats];
        front = rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == max_seats;
    }

    bool isEmpty() {
        return size == 0;
    }

    void addPatient(string Name) {
        if (!isFull()) {
            rear = (rear + 1) % max_seats;
            queue[rear] = Name;
            cout << "Patient Added: " << Name << endl;
            size++;
        } else {
            cout << "Queue is full" << endl;
        }
    }

    void SndPatient() {
        if (!isEmpty()) {
            cout <<queue[rear] <<" is sent to the doctor" << endl;
           int c=rear;
           c = (c + 1) % max_seats;
        } else {
            cout << "No Patient" << endl;
        }
    }

    void display_patient() {
        if (!isEmpty()) {
            cout << "Patient Queue:" << endl;
            int c = front;
            for (int i = 0; i < size; ++i) {
                cout << i + 1 << ". " << queue[c] << endl;
                c = (c + 1) % max_seats;
            }
        } else {
            cout << "Queue is empty. No patients waiting." << endl;
        }
    }
    void display_next_patient(){
        int c=rear;
        cout<<"Next Patient"<<c+1<<endl;
    }
    ~Doc() {
        delete[] queue;
    }
};

int main() {
    Doc D(14);
    string name;
    int choice;

    while (true) {
        cout << "Press 1 for add a patient" << endl;
        cout << "Press 2 for sending a patient" << endl;
        D.display_next_patient();
        cout << "Press 3 to see whole patient" << endl;
        cout << "Press 4 for exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient Name" << endl;
                cin >> name;
                D.addPatient(name);
                break;
            case 2:
                D.SndPatient();
                break;
            case 3:
                D.display_patient();
                break;
            case 4:
                cout << "Have a Great Day" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
