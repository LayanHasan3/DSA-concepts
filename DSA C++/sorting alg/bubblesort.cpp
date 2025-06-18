#include<iostream>
using namespace std;
int main()
{
    int size;
  cout<<"enter size of array: ";
  cin>>size;
  int arr[size];
  cout<<"enter array elements: "<<endl;
  for(int i=0;i<size;i++)
  {
      cin>>arr[i];
  }
  for(int i=0;i<size;i++)
  {
    for(int j=i+1;j<size;j++)
    {
        if(arr[i]>arr[j]){
            swap(arr[i],arr[j]);
        }
    }
  }
    cout<<"sorted array is: "<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}