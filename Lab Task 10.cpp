#include <iostream>
#include <string>
using namespace std;

class Gem {
public:
    string name;
    int power;
    Gem* left;
    Gem* right;

    Gem(string n, int p) : name(n), power(p), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Gem* root;
    int bagPower;  
    int bagCapacity; 

public:
    BST(int capacity) : root(nullptr), bagPower(0), bagCapacity(capacity) {}

    Gem* insert(Gem* current, string name, int power) {
        if (current == nullptr) {
            return new Gem(name, power);
        }

        if (power < current->power) {
            current->left = insert(current->left, name, power);
        }
        else if (power > current->power) {
            current->right = insert(current->right, name, power);
        }

        return current;
    }

    Gem* search(Gem* current, int power) {
        if (current == nullptr || current->power == power)
            return current;
        if (power < current->power)
            return search(current->left, power);
        return search(current->right, power);
    }

    Gem* findMax(Gem* current) {
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

  Gem* deleteNode(Gem* current, int powerToDelete) {
    if (current == nullptr) return current;

    if (powerToDelete < current->power) {
        current->left = deleteNode(current->left, powerToDelete);
    }
    else if (powerToDelete > current->power) {
        current->right = deleteNode(current->right, powerToDelete);
    }
    else {
      
        if (current->left == nullptr && current->right == nullptr) {
           
            delete current;
            return nullptr;
        }
        else if (current->left == nullptr) {
          
            Gem* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr) {
          
            Gem* temp = current->left;
            delete current;
            return temp;
        }
    }
    return current;
}


    Gem* findMin(Gem* current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }


    void Display(Gem* current) {
        if (current == nullptr) return;
        Display(current->left);
        cout << current->name << " (" << current->power << ") ";
        Display(current->right);
    }

   
    void Post_Order(Gem* current) {
        if (current == nullptr) return;
        Post_Order(current->left);
        Post_Order(current->right);
        cout << current->name << " (" << current->power << ")" << endl;
    }

   
    void Pre_Order(Gem* current) {
        if (current == nullptr) return;
        cout << current->name << " (" << current->power << ")" << endl;
        Pre_Order(current->left);
        Pre_Order(current->right);
    }
};

int main() {
    BST E_F(100);  
    int choice;
    int choice2;
    int real_power=100;

    E_F.root = E_F.insert(E_F.root, "Power_Stone", 50);
    E_F.root = E_F.insert(E_F.root, "Mind_Stone", 30);
    E_F.root = E_F.insert(E_F.root, "Soul_Stone", 70);
    E_F.root = E_F.insert(E_F.root, "Chill_Stone", 40);
    E_F.root = E_F.insert(E_F.root, "Opal", 10);
    E_F.root = E_F.insert(E_F.root, "Garnet", 60);
    E_F.root = E_F.insert(E_F.root, "Zircon", 20);
    E_F.root = E_F.insert(E_F.root, "Jade", 5);
    
    while (1) {
        cout << "Press 1 for Displaying The Tree" << endl;
        cout << "Press 2 for Searching A Specific Gem" << endl;
        cout << "Press 3 for Highest Gem Power" << endl;
        cout << "Press 4 for Deleting a Gem" << endl;
        cout << "Press 5 for Escape Jujustu" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Press 1 for Pre-Order\n2 for Post-Order\n3 for In-Order" << endl;
            cin >> choice2;
            if (choice2 == 1) {
                E_F.Pre_Order(E_F.root);
            }
            else if (choice2 == 2) {
                E_F.Post_Order(E_F.root);
            }
            else if (choice2 == 3) {
                E_F.Display(E_F.root);
            }
        }
        if (choice == 2) {
            int power;
            cout << "Please input the power of Gem" << endl;
            cin >> power;
            Gem* result = E_F.search(E_F.root, power);
            if (result != nullptr) {
                cout << "Found gem: " << result->name << " (" << result->power << ")" << endl;
            }
            else {
                cout << "Gem not found." << endl;
            }
        }
        if (choice == 3) {
            Gem* highestPowerGem = E_F.findMax(E_F.root);
            cout << "Gem with the highest power: " << highestPowerGem->name << " (" << highestPowerGem->power << ")" << endl;
        }
        if (choice == 4) {
            int power;
            cout << "Please input the power of Gem to delete" << endl;
            cin >> power;
            real_power=real_power-power;
            E_F.root = E_F.deleteNode(E_F.root, power);
            cout << "Gem deleted." << endl;
            if(real_power ==100 )
            {
                cout<<"Bag is full"<<endl;
            }
            if(real_power <0)
            {
                cout<<"Bag exploded.Make Sure You equip Bag Level   3 next time"<<endl;
            }
        }
        if (choice == 5) {
            break;
        }
    }
    return 0;
}
