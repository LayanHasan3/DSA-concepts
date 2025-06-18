#include <iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>arr, int target, int st, int end)
{
    if(st<=end)
    {
    int mid=st+(end-st)/2;
    if(arr[mid]<target)
    {
       return binarysearch(arr,target,st=mid+1,end);
    }
    else if(arr[mid]>target)
    {
       return binarysearch(arr,target,st,end=mid-1);
    }
    else{
        return mid;
    }
 }
    return 0;
}
int main() {
    int n=7;
    int start=0;
    int end=n-1;
    vector<int>arr={-1,0,3,4,5,9,12};
    int target;
    cout<<"enter search value: "<<endl;
    cin>>target;
    cout<<binarysearch(arr, target, start, end)<<endl;
    return 0;
}