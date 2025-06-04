#include <iostream>
#include <string>
using namespace std;

#define z 100

class MyStack {
    char* block;
    int top;

public:
    MyStack() {
        block = new char[z];
        top = -1;
    }

    void push(char x) {
        if (top == z - 1) {
            cout << "Stack Full" << endl;
            return;
        }
        top++;
        block[top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
            return;
        }
        top--;
    }

    char topElement() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
            return '\0';
        }
        return block[top];
    }

    bool empty() {
        return top == -1;
    }

    void print() {
        int i = top;
        while (i >= 0) {
            char s = block[i];
            cout << s << endl;
            i--;
        }
    }
};

bool Checkingbracket(string word) {
    MyStack g;
    for (int i = 0; i < word.length(); i++) {
        char set = word[i];

        switch (set) {
            case '(':
            case '{':
            case '[':
                g.push(set);
                break;
            case ')':
                if (g.empty() || g.topElement() != '(') {
                    return false;
                }
                g.pop();
                break;
            case '}':
                if (g.empty() || g.topElement() != '{') {
                    return false;
                }
                g.pop();
                break;
            case ']':
                if (g.empty() || g.topElement() != '[') {
                    return false;
                }
                g.pop();
                break;
        }
    }
    
   
    if (!g.empty()) {
        return false;
    }
    
    return true;
}

/*
((x + y) * (z - w))=correct
{a + [b - c]}=correct
{a + [b - c)"}=Not Correct
((a + b) * {c - [d / e)})=not correct
*/
int main() {
    string input;

    cout << "Enter a statement with brackets for analysis: ";
    getline(cin, input);
    if (Checkingbracket(input)) {
        cout << "It's in order and are correct" << endl;
    } else {
        cout << "Brackets are not correct or not in sequence" << endl;
    }

    return 0;
}
