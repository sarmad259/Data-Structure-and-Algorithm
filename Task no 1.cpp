#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *y; 
    *y = *x;       
    *x = temp;     
}

int main() {
    int a, b;
    cout << "Enter Two Values :";
    cin >> a;
    cin >> b;
    cout << "Numbers Before Swapping " << a << "\t" << b << endl;
    swap(&a, &b); 
    cout << "Numbers After Swapping " << a << "\t" << b << endl;
    return 0;
}
