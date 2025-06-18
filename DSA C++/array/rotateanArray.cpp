#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"Enter the number of rotations: ";
    cin>>d;
    int temp[n];
    
    for(int i=0;i<n-d;i++){
        temp[i]=arr[d+i];
    }
    for(int i=0;i<d;i++){
        temp[n-d+i]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    cout<<"The rotated array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;   
}