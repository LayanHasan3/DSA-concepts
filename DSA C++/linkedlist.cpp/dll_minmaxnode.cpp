#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

node* head = NULL;
node* tail = NULL;

// Insert node at end
void insert() {
    node* ptr = (node*)malloc(sizeof(node));
    cout << "Enter the data: ";
    cin >> ptr->data;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (head == NULL) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

// Delete a node by value
void Delete() {
    int key;
    cout << "Enter the key you want to delete: ";
    cin >> key;
    node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
    cout << "Node deleted successfully!\n";
}

// Search a node
void search() {
    int key;
    cout << "Enter the key you want to search: ";
    cin >> key;
    node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Key found!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Key not found!\n";
}

// Display all nodes
void display() {
    node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Count total nodes
int countNodes() {
    int count = 0;
    node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Find middle value
void findMiddle() {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow)
        cout << "Middle node value: " << slow->data << endl;
}

// Move min value to front
void moveMinToFront() {
    if (head == NULL) return;

    node* minNode = head;
    node* temp = head->next;

    while (temp) {
        if (temp->data < minNode->data)
            minNode = temp;
        temp = temp->next;
    }

    if (minNode == head) return;

    // Remove minNode
    if (minNode->prev) minNode->prev->next = minNode->next;
    if (minNode->next) minNode->next->prev = minNode->prev;
    if (minNode == tail) tail = minNode->prev;

    // Move to front
    minNode->next = head;
    head->prev = minNode;
    minNode->prev = NULL;
    head = minNode;

    cout << "Moved min (" << minNode->data << ") to front.\n";
}

// Move max value to end
void moveMaxToEnd() {
    if (head == NULL) return;

    node* maxNode = head;
    node* temp = head->next;

    while (temp) {
        if (temp->data > maxNode->data)
            maxNode = temp;
        temp = temp->next;
    }

    if (maxNode == tail) return;

    // Remove maxNode
    if (maxNode->prev) maxNode->prev->next = maxNode->next;
    if (maxNode->next) maxNode->next->prev = maxNode->prev;
    if (maxNode == head) head = maxNode->next;

    // Move to end
    maxNode->prev = tail;
    maxNode->next = NULL;
    tail->next = maxNode;
    tail = maxNode;

    cout << "Moved max (" << maxNode->data << ") to end.\n";
}

int main() {
    insert(); insert(); insert(); insert();
    display();

    search();
    Delete();
    display();

    cout << "Total nodes: " << countNodes() << endl;
    findMiddle();

    moveMinToFront();
    display();

    moveMaxToEnd();
    display();

    return 0;
}
