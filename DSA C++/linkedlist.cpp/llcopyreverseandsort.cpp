#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert data into the list in sorted order
void insert(int data) {
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL || head->data >= ptr->data) {
        ptr->next = head;
        head = ptr;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL && curr->next->data < ptr->data) {
            curr = curr->next;
        }
        ptr->next = curr->next;
        curr->next = ptr;
    }
}

// Function to search for an element in the list
void search() {
    int tosearch;
    cout << "Enter the element to search: ";
    cin >> tosearch;
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == tosearch) {
            cout << "Searched element is found" << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Element not found" << endl;
}

// Function to print the list
void print() {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to delete an element from the list
void Delete() {
    int todel;
    cout << "Enter the element to delete: ";
    cin >> todel;
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (todel == head->data) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    else {
        Node* curr = head->next;
        Node* prev = head;
        while (curr != NULL) {
            if (curr->data == todel) {
                prev->next = curr->next;
                free(curr);
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
    }
}

// Function to copy the list and reverse it
Node* copyAndReverse() {
    Node* reversedList = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = curr->data;
        newNode->next = reversedList;
        reversedList = newNode;
        curr = curr->next;
    }

    return reversedList;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        insert(data);
    }

    cout << "Original List: ";
    print();

    // Copy and reverse the list
    Node* reversedHead = copyAndReverse();
    cout << "Reversed List: ";
    Node* curr = reversedHead;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    search();
    Delete();
    cout << "List after deletion: ";
    print();

    return 0;
}
