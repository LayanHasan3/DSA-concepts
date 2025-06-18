#include <iostream>
using namespace std;

int hashFunction(int key, int size) 
{
    return key % size;
}
void insert(int hashTable[], int key, int size) 
{
    int index = hashFunction(key, size);
    while (hashTable[index] != -1) 
	{
        index = (index + 1) % size;
    }
    hashTable[index] = key;
    cout << "Key " << key << " inserted at index " << index << endl;
}

void search(int hashTable[], int key, int size) {
    int index = hashFunction(key, size);

   
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            cout << "Key " << key << " found at index " << index << endl;
            return;
        }
        index = (index + 1) % size;
    }
    cout << "Key " << key << " not found." << endl;
}

void display(int hashTable[], int size) {
    cout << "Hash Table: " << endl;
    for (int i = 0; i < size; i++) {
        if (hashTable[i] != -1)
            cout << "Index " << i << ": " << hashTable[i] << endl;
        else
            cout << "Index " << i << "-1" << endl;
    }
}

int main() {
    int size;

    cout << "Enter the size of the hash table: ";
    cin >> size;

    int* hashTable = new int[size];
    for (int i = 0; i < size; i++) {
        hashTable[i] = -1;
    }

    int option, key;
    do {
        cout << "\nOptions:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(hashTable, key, size);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                search(hashTable, key, size);
                break;
            case 3:
                display(hashTable, size);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);
   
    return 0;
}
