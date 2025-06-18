#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

struct Node {
    int data;
    Node* next;
};

int hashFunction(int key, int size) {
    return key % size;
}

void insert(Node** hashTable, int key, int size) {
    // Malloc allocates raw memory, we cast it to Node*
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    int index = hashFunction(key, size);

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Key " << key << " inserted at index " << index << endl;
}

void display(Node** hashTable, int size) {
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        Node* temp = hashTable[i];
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void Delete(Node** hashTable, int size) {
    for (int i = 0; i < size; i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            Node* next = current->next;
            free(current); // free instead of delete
            current = next;
        }
    }
    free(hashTable); // free the table itself
}

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    // Allocate memory for hash table
    Node** hashTable = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        hashTable[i] = NULL;
    }

    int keys[] = {78, 71, 60, 98, 22, 118};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i], size);
    }

    display(hashTable, size);

    // Free the memory
    Delete(hashTable, size);

    return 0;
}
