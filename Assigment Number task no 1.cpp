#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

class Stack {
public:
    int top;
    int arr[100]; 

    Stack() {
        top = -1;
    }

    bool checkEmpty() {
        return top == -1;
    }

    bool checkFull() {
        return top == 99;
    }

    void push(int val) {
        if (!checkFull()) {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (!checkEmpty()) {
            int popValue = arr[top];
            top--;
            return popValue;
        }
        return -1;
    }

    int peek() {
        if (!checkEmpty()) {
            return arr[top];
        }
        return -1;
    }
};

int evaluatePostfix(string exp) {
    Stack stack;
    stringstream ss(exp); 
    string Pass;
    while (ss >> Pass) {
        if (Pass[0] >= '0' && Pass[0] <= '9') {
            int num = Pass[0] - '0'; 
            stack.push(num);
        } else if (Pass.size() == 1 && (Pass[0] == '+' || Pass[0] == '-' || Pass[0] == '*' || Pass[0] == '/')) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (Pass[0]) {
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
            }
        } else {
            cout << "Invalid : " << Pass << endl;
            return -1;
        }
    }

    if (!stack.checkEmpty()) {
        return stack.peek();
    } else {
        cout << "Invalid expression" << endl;
        return -1;
    }
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    int result = evaluatePostfix(exp);
    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
