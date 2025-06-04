#include<iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
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

    void push(int val) {
        if (!checkFull()) {
            top++;
            arr[top] = val;
            cout << "Value '" << val << "' is pushed onto the stack" << endl;
        }
        else {
            cout << "Stack is full. Cannot push " << val << " onto the stack." << endl;
        }
    }

    int pop() {
        if (!checkEmpty()) {
            int popValue = arr[top];
            top--;
     
            return popValue;
        }
        else {
            cout << "Stack is empty. Cannot pop from an empty stack." << endl;
            return -1;  // You can choose a different value to indicate an error condition
        }
    }
    
};
int evaluatePostfix(const string& expression) {
    Stack stack(100);  // Assuming a maximum of 100 elements in the stack

    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');  // Convert character to integer
        }
        else if(c==' ')
        {

        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Error: Unknown operator '" << c << "'" << endl;
                    exit(EXIT_FAILURE);
            }
        }
    }

    return stack.pop();
}
int main() {
    string postfixExpression = "7+8 -7";  // Example postfix expression: (2 + 3) * 4
    int result = evaluatePostfix(postfixExpression);

    cout << "Result: " << result << endl;

    return 0;
}