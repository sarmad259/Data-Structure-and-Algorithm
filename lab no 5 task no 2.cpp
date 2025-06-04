#include <iostream>
using namespace std;

class Stack {
public:
    int top;
    string* arr;
    int size;

    Stack(int size) {
        top = -1;
        this->size = size;
        arr = new string[size];
    }
    ~Stack() {
        delete[] arr;
    }
    bool checkEmpty() {
        return top == -1;
    }

    bool checkFull() {
        return top == size - 1;
    }

    void push(const string& val) {
        if (!checkFull()) {
            top++;
            arr[top] = val;
            cout << "Value '" << val << "' is pushed onto the stack" << endl;
        }
    }

    string pop() {
        if (!checkEmpty()) {
            string popValue = arr[top];
            top--;
            return popValue;
        }
        return "";
    }
};

void reversethearray(Stack& s) {
    string reverse[10];
    for (int i = 0; i < 10; i++) {
        reverse[i] = s.pop();
        cout << "Value after changing are '" << reverse[i] << "'" << endl;
    }
}

int main() {
    Stack s(10);
    
    for (int i = 1; i <= 10; i++) {
        s.push(to_string(i));
    }

    reversethearray(s);
    return 0;
}
