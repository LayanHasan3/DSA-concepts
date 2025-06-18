#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr, int start, int mid, int end)
{
    vector<int>temp;
    int i=start;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int ind=0;ind<temp.size();ind++)
    {
        arr[start+ind]=temp[ind];
    }
}
void mergesort(vector<int>&arr, int start,int end)
{
    if(start<end){
        int  mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    vector<int>arr={5,4,3,2,1};
    int n=arr.size();
    int start=0;
    int end=n-1;
    mergesort(arr,start,end);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}