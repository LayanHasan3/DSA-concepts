#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert a node at the end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to swap two nodes without swapping data
void swapNodes(int x, int y) {
    if (x == y) return; // No need to swap if both are the same

    Node *prevX = nullptr, *currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = nullptr, *currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) {
        cout << "One or both elements not found!\n";
        return;
    }

    if (prevX) {
        prevX->next = currY;
    } else {
        head = currY;
    }

    if (prevY) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

// Function to display the linked list
void display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    int x, y;
    cout << "Enter two elements to swap: ";
    cin >> x >> y;

    swapNodes(x, y);

    cout << "List after swapping: ";
    display();

    return 0;
}
