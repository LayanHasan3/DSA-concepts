#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void inputArray(int arr[], int &size) {
    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100], size;
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Input array\n";
        cout << "2. Sort array using Quick Sort\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputArray(arr, size);
                break;
            case 2:
                quickSort(arr, 0, size - 1);
                cout << "Array sorted successfully!\n";
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again!\n";
        }
    } while (choice != 4);

    return 0;
}
