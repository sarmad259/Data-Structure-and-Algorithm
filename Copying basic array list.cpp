#include <iostream>
#include <string>
using namespace std;
int main()
{
    int *arr1=new int[5];
    int arr2[5];
    int *current=arr2;
    for (int i = 0; i <5;i++)
    {
        cout<<"ENTER Elements      "<<i+1<<endl;
        cin>>arr1[i];
    }
     for (int i = 0; i <5;i++)
     {
    arr2[i]=arr1[i];
     }
    delete[] arr1;
   
    for (int i = 0; i <5;i++)
    {
        cout<<"Elements of array 2 are    "<<arr2[i]<<endl;
    }
    int choice;
cout<<"Do ya want to show the first elemnt of array"<<endl;
cin >>choice;
if(choice ==1)
{
    cout<<"First element "<<*current;
}
else{
    current++;
    cout<<"Second element"<<*current<<endl;
}
    return 0;
}