#include<iostream>
using namespace std;
int main()
{
    int arr[5],key,index;
    bool flag=false;
    cout<<"enter your array:";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    cout<<"enter the key to search:";
    cin>>key;

    for(int i=0;i<5;i++){
        if(arr[i]==key){
            flag=true;
            index=i;
            break;
        }
    }
    if(flag==false){
        cout<<"key not found";
    }
    else{
        cout<<"key found at index:"<<index;
    }
    cout<<endl;
    return 0;
}