#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));

    char Box[3][3];
    int Old_Row = 3 / 2;
    int Old_Col = 3 / 2;

    for (int g = 0; g < 3; g++) {
        for (int n = 0; n < 3; n++) {
            Box[g][n] = '-';
        }
    }
    Box[Old_Row][Old_Col] = '.';

    for (int f = 0; f < 2; f++) {
        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (Box[row][col] != '-');
        Box[row][col] = 'x';
    }

    for (int i = 0; i < 1; i++) {
        int row, col;
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (Box[row][col] != '-');
        Box[row][col] = 'R';
    }

    char* P_Pos = &Box[Old_Row][Old_Col];
    string choice;
    for (int z = 0; z < 3; z++) {
            for (int v = 0; v < 3; v++) {
                cout << Box[z][v] << " ";
            }
            cout << endl;
        }
    
    while (true) {
    cout << "Type the direction to move (Left/Right/Up/Down) or press 'Q' to quit: ";
    cin >> choice;

    if (choice == "Q" || choice == "q") {
        break;
    }

    char* new_P_Pos = P_Pos;  

    if (choice == "Left" && Old_Col > 0) {
        new_P_Pos--;
    } else if (choice == "Right" && Old_Col < 2) {
        new_P_Pos++;
    } else if (choice == "Up" && Old_Row > 0) {
        new_P_Pos -= 3;
    } else if (choice == "Down" && Old_Row < 2) {
        new_P_Pos += 3;   } else {
        cout << "Invalid Option" << endl;
        continue;
    }

    
    if (*new_P_Pos == '-' || *new_P_Pos == 'R' || *new_P_Pos == 'x') {
        *P_Pos = '-';        
         P_Pos = new_P_Pos;
        *P_Pos = '.';  
        
     if (*P_Pos == 'R') {
            cout << "You Won" << endl;
            break;
        }
        if (*P_Pos == 'x') {
            cout << "You hit a Bomb" << endl;
            break;
        }
}
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << Box[i][j] << " ";
            }
            cout << endl;
        }
    } 

cout << "The End" << endl;
return 0;


    cout << "The End" << endl;
    return 0;
}
