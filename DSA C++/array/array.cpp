#include<iostream>
using namespace std;
int main(){
    int size;
    int arr[10];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements of the array are: ";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    arr[7]=57;
    cout<<endl<<"The elements of the array are: ";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}