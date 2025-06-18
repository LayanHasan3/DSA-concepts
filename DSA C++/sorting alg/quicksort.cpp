#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int start,int end)
{
    int ind=start-1;
    int pivot=arr[end];
    for(int j=start;j<end;j++)
    {
        if(arr[j]<=pivot)
        {
            ind++;
            swap(arr[j],arr[ind]);
        }
    }
    ind++;
    swap(arr[ind],arr[end]);
    return ind;
}
void quicksort(vector<int>&arr, int start,int end)
{
    if(start<end)
    {
        int pivindex=partition(arr,start,end);
        quicksort(arr,start,pivindex-1);
        quicksort(arr,pivindex+1,end);
    }
}
int main()
{
    vector<int>arr={5,2,6,4,1,3};
    int n=arr.size();
    int start=0;
    int end=n-1;
    quicksort(arr,start,end);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}