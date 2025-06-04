#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
    int top;
    char* arr;
    int size;

    Stack(int size) {
        top = -1;
        this->size = size;
        arr = new char[size];
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

    void push(char val) {
        if (!checkFull()) {
            top++;
            arr[top] = val;
        }
    }

    char pop() {
        if (!checkEmpty()) {
            char popValue = arr[top];
            top--;
            return popValue;
        }
        return '\0'; 
    }
};

string reverseString(const string& input) {
    Stack s(input.length());
    
    for (char c : input) {
        s.push(c);
    }

    string reversed;
    while (!s.checkEmpty()) {
        reversed += s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
