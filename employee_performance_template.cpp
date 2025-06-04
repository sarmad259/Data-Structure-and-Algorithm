#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    int employeeID;
    string name;
    float sales;
    float customerSatisfaction;
    float projectCompletion;
    float performanceScore;

    Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion, float sales) {
        this->employeeID = employeeID;
        this->name = name;
        this->sales = sales;
        this->customerSatisfaction = customerSatisfaction;
        this->projectCompletion = projectCompletion;
    }

    void calculatePerformanceScore() {
        performanceScore = sales + customerSatisfaction + projectCompletion;
    }

    void display_performance() {
        cout << name << " and score " << performanceScore << endl;
    }
};

class MaxHeap {
public:
    vector<Employee> employeeHeap;

    int getParent(int child) {
        int a = (child - 1) / 2;
        if (child == 0) {
            return -1;
        }
        else if (a < employeeHeap.size()) {
            return a;
        }
        else
            return -1;
    }

    int getLeft(int parent) {
        int a = 2 * parent + 1;
        if (a < employeeHeap.size())
        {
            return a;
        }
        else
            return -1;
    }

    int getRight(int parent) {
        int a = 2 * parent + 2;
        if (a < employeeHeap.size())
        {
            return a;
        }
        else
            return -1;
    }

    void swap(Employee* a, Employee* b) {
        Employee temp = *a;
        *a = *b;
        *b = temp;
        temp = *a; 
        temp.performanceScore = a->performanceScore;
    }

    void heapifyUp(int node) {
        int parent = getParent(node);
        if (node >= 0 && parent != -1 && employeeHeap[parent].performanceScore < employeeHeap[node].performanceScore) {
            swap(&employeeHeap[parent], &employeeHeap[node]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node) {
        int left = getLeft(node);
        int right = getRight(node);
        int largest = node;
        if (left != -1 && employeeHeap[left].performanceScore > employeeHeap[largest].performanceScore) {
            largest = left;
        }
        if (right != -1 && employeeHeap[right].performanceScore > employeeHeap[largest].performanceScore) {
            largest = right;
        }
        if (largest != node) {
            swap(&employeeHeap[node], &employeeHeap[largest]);
            heapifyDown(largest);
        }
    }

    void insertEmployee(Employee val) {
        int size = employeeHeap.size();
        if (size == 0) {
            employeeHeap.push_back(val);
        }
        else {
            employeeHeap.push_back(val);
            heapifyUp(employeeHeap.size() - 1);
        }
    }

    void getTopRankingEmployee() {
        if (employeeHeap.empty()) {
            cout << "No Employees." << endl;
            return;
        }
        cout << "Top Ranking Employee: ";
        employeeHeap[0].display_performance();
    }

    void updatePerformance(int employeeID, float newSales, float newCS, float newPCE) {
    bool found = false;
    for (Employee& emp : employeeHeap) {
        if (emp.employeeID == employeeID) {
            emp.sales = newSales;
            emp.customerSatisfaction = newCS;
            emp.projectCompletion = newPCE;
            emp.calculatePerformanceScore();
            found = true;
            break;
        }
    }
    if (found) {
        // Reconstruct the heap to maintain the heap property
        for (int i = employeeHeap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
        cout << "Performance scores updated successfully!" << endl;
    } else {
        cout << "Employee ID not found!" << endl;
    }
}


    void displayEmployees() {
        if (employeeHeap.empty()) {
            cout << "No Employees." << endl;
            return;
        }
        cout << "Employee Rankings:" << endl;
        for (const Employee& emp : employeeHeap) {
            cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
        }
    }
};

int main() {
    MaxHeap employeeMaxHeap;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter a new employee details\n";
        cout << "2. Get the top-ranking employee\n";
        // Add options for updating and displaying employees
        cout << "3. Update an employee's scores\n";
        cout << "4. Display employee rankings\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float sales, cs, pce;
                cout << "Enter Employee ID: ";
                cin >> id;
                cin.ignore(); // Clear newline character from the buffer
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Sales (in percentage): ";
                cin >> sales;
                cout << "Enter Customer Satisfaction (in percentage): ";
                cin >> cs;
                cout << "Enter Project Completion Efficiency (in percentage): ";
                cin >> pce;

                Employee newEmployee(id, name, cs, pce, sales);
                newEmployee.calculatePerformanceScore();
                employeeMaxHeap.insertEmployee(newEmployee);
                cout << "Employee added successfully!" << endl;
                break;
            }
            case 2: {
                employeeMaxHeap.getTopRankingEmployee();
                break;
            }
         
            case 3: {
                 int id;
                string name;
                float sales, cs, pce;
				 cout << "Enter Employee ID for search: ";
                cin >> id;
                cin.ignore(); // Clear newline character from the buffer
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Sales (in percentage): ";
                cin >> sales;
                cout << "Enter Customer Satisfaction (in percentage): ";
                cin >> cs;
                cout << "Enter Project Completion Efficiency (in percentage): ";
                cin >> pce;
               employeeMaxHeap.updatePerformance(id,sales,cs,pce);
                break;
            }
            case 4: {
                employeeMaxHeap.displayEmployees();
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
