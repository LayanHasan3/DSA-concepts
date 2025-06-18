#include<iostream>
using namespace std;
int main(){
    string food = "karahi";
    string* ptr = &food;
    cout<<food<<endl;
    cout<<&food<<endl;
    cout<<*ptr<<endl; //dereferencing the pointer
    cout<<ptr<<endl;
    *ptr = "biryani"; //modifying the pointer value changes the original value as well.
    cout<<food<<endl;
    cout<<ptr<<endl;
    // C++ program to demonstrate accessing array's first
// element using array name and pointer
    int arr[5] = { 1, 2, 3, 4, 5 };
    int* abc = arr;

    // printing first element of an array using array name
    // and dereference operator
    cout << "*arr = " << *arr << endl;
    cout << "arr = " << arr << endl;
    cout << "*ptr = " << *abc << endl;
    cout << "ptr = " << abc << endl;

    return 0;
}
