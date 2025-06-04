#include<iostream>
using namespace std;        
class node{
    public:
    node *next;
    node *rev;
    int data;
    node(int data) 
    {
        this->data = data;
        next=nullptr;
        rev=nullptr;
    }

};
class circular{
    public:
    node *head;
    
}