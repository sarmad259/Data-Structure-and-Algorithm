#include<iostream>
#include<string>
using namespace std;
class Hashtable {
private:
    int sze; 
    int cap; 

    struct Node_Hash {
         string Number;
    };

    Node_Hash** arr;

    bool isPrime(int No) {
    if (No == 2 || No == 3)
        return true;

   while (No % 2 == 0 || No % 3 == 0) {
    return false;
}


    int Div = 6;
    for (; Div * Div - 2 * Div + 1 <= No; Div += 6) {
        if (No % (Div - 1) == 0)
            return false;

        if (No % (Div + 1) == 0)
            return false;
    }

    return true;
}


  int Up_Prime(int a) {
    for (; !isPrime(a); ++a) {
      
    }
    return a;
}


   int hashing(const  string& str) const {
    int h = 0;
    auto it = str.begin();

    while (it != str.end()) {
        h += static_cast<int>(*it);
        ++it;
    }

    return h;
}


void rehashing() {
  int oldCap = cap;
  sze = 0;
  cap = Up_Prime(cap * 2);

  Node_Hash** Old_Array = arr;
  arr = new Node_Hash*[cap]();

  for (int i = 0; i < oldCap; ++i) {
    if (Old_Array[i] != nullptr) {
      put(Old_Array[i]->Number);
      delete Old_Array[i];
    }
  }

  delete[] Old_Array;
}


public:
  
   Hashtable(int ini_cap = 101) : cap(ini_cap) {
    sze = 0;
    arr = new Node_Hash*[cap];

    int i = 0;
    while (i < cap) {
        arr[i] = nullptr;
        ++i;
    }
}

    ~Hashtable() {
    int i = 0;
    while (i < cap) {
        if (arr[i] != nullptr) {
            delete arr[i];
            arr[i] = nullptr;
        }
        ++i;
    }
    delete[] arr;
}

    double Load() const { return static_cast<double>(sze) / cap; }//for calculating load

    void put(const  string& s) {

    Node_Hash* newNode = new Node_Hash{s};

    int i = 0;
    while (i < cap) {
        int  Ind = (hashing(s) + i * i) % cap;
        if (arr[ Ind] == nullptr) {
            arr[ Ind] = newNode;
            sze++;
            break;
        }
        ++i;
    }

        if (Load() >0.70) {//if condition for load if greater than 70% then use rehashing
            rehashing();
        } 
    } 
};

int main() {
    Hashtable myHashTable;
int i=0;
    while(i <= 77)
    {
        myHashTable.put("five");
        i++;
    }   

     cout << "Load Factor: " << myHashTable.Load() <<  endl;

    return 0;
}
