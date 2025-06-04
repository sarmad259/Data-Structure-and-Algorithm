#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[]) {
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    display(size, arr);
    cout << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[]) {
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        display(size, arr);
    }
    cout << "Selection Sort Comparisons: " << comparisons << endl;
}

void insertionSort(int size, int arr[]) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        int n = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > n) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = n;
        display(size, arr);
    }
    cout << "Insertion Sort Comparisons: " << comparisons << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int midL = left + n1 / 2;
    int midR = mid + 1 + n2 / 2;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            comparisons++;   
            return mid;
        }

        if (arr[mid] > key) {
            comparisons++;   
            return binarySearchRecursive(arr, left, mid - 1, key, comparisons);
        }

        comparisons++;   
        return binarySearchRecursive(arr, mid + 1, right, key, comparisons);
    }

    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid2 = left + (right - left) / 2;

        if (arr[mid2] == key) {
            comparisons++;  
            return mid2;
        }

        if (arr[mid2] > key) {
            comparisons++;  
            right = mid2 - 1;
        } else {
            comparisons++; 
            left = mid2 + 1;
        }
    }

    return -1;
}

void add_and_sort_arrays(int array1[], int array2[], int size) {
    int arr_w[2 * size];

    for (int i = 0; i < size; i++) {
        arr_w[i] = array1[i];
        arr_w[size + i] = array2[i];
    }

    // Iterate through arr_w and find the maximum element
    for (int i = 0; i < 2 * size; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < 2 * size; j++) {
            if (arr_w[j] > arr_w[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap the maximum element with the current element
        swap(arr_w[i], arr_w[maxIndex]);
    }

    cout << "Merged and Sorted Array: ";
    display(2 * size, arr_w);
}


int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    int arr2[size];

    cout << "Enter the elements of the array1:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the elements of the array2:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr2[i];
    }

    // Display the menu
    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Binary Search (Recursive)\n";
    cout << "6. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(size, arr);
            break;
        case 2:
            selectionSort(size, arr);
            break;
        case 3:
            insertionSort(size, arr);
            display(size, arr);
            break;
        case 4:
            mergeSort(arr, 0, size - 1);
            mergeSort(arr2, 0, size - 1);
            display(size, arr);
            display(size, arr2);
            add_and_sort_arrays(arr, arr2, size);
            break;
        case 5: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchRecursive(arr, 0, size - 1, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        case 6: {
            int key;
            cout << "Enter the value to find: ";
            cin >> key;
            int comparisons = 0;
            int result = binarySearchIterative(arr, size, key, comparisons);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found\n";
            }
            cout << "Comparisons: " << comparisons << endl;
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
