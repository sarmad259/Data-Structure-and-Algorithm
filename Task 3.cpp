#include <iostream>
using namespace std;

int main() {
    int t[4][7];  // Declare a 2D array t with 4 rows and 7 columns

    // Fill the 2D array t with random values between 10 and 30
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            t[i][j] = rand() % 21 + 10;  // Generates a random number between 10 and 30
        }
    }

    // Print the 2D array t
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            cout << *(*(t + i) + j) << "\t";  // Access and print the value at row i and column j
        }
        cout << endl;
    }

    // Find and print the hottest day for each week
    for (int i = 0; i < 4; i++) {
        int *Max_Pointer = *(t + i);  // Pointer to the current week's array
        int Max_Value = 0;  // Index of the hottest day, initialized to 0

        // Iterate through the current week's array to find the hottest day
        for (int j = 1; j < 7; j++) {
            if (*(Max_Pointer + j) > *(Max_Pointer + Max_Value)) {
                Max_Value = j;  // Update Max_Value if a hotter day is found
            }
        }

        // Print the week's temperatures and the hottest day
        cout << "Week " << i + 1 << ": ";
        for (int j = 0; j < 7; j++) {
            cout << *(*(t + i) + j) << " ";  // Print the temperatures for the week
        }
        cout << "Hottest Day of Week : Day" << Max_Value + 1 << " (" << *(Max_Pointer + Max_Value) << "°C)\n";
    }

    return 0;
}
