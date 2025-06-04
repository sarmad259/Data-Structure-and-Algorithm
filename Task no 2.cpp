#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string word;
    int choice;
    cout << "Enter a String: ";
    cin >> word;
    while(1)
    {
    cout << "Now Press 1 to check if the number is palindrome\nPress 2 to check the frequency of a certain character\n Press 3 to exit" << endl;
    cin >> choice;

    if (choice == 1) {
        bool statement = true;

        const char *pointer_start = word.c_str();
        const char *pointer_end = word.c_str() + strlen(word.c_str()) - 1;

        while (pointer_start < pointer_end) {
            if (*pointer_start != *pointer_end) { 
                statement = false;
                break;
            }
            pointer_start++;
            pointer_end--;
        }

        if (statement) {
            cout << "\nPalindrome" << endl;
        } else {
            cout << "Not Palindrome" << endl;
        }
    }  if (choice == 2) {
        char Matched;
        cout << "Enter the word to count : ";
        cin >> Matched;

        int Num = 0;
        for (char c : word)
        {
            if (c == Matched) {
                Num++;
            }
        }
        cout << "The frequency of required character " << Matched << " is: " << Num << endl;
    }
         if(choice ==3)
        {
        goto x;
        }
     else {
        cout << "Invalid Choice" << endl;
    }
    }
    x:
    return 0;
}
