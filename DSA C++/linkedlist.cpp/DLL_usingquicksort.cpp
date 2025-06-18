#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
//head and tail pointers are initially empty
Node* head = NULL;
Node* tail = NULL;

// Insert at the end
void insert() {
    Node* newNode = new Node();
    cout << "Enter data: ";
    cin >> newNode->data;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// print func
void print() {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL";
}

// Partition func for Quick Sort
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i->data, high->data);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (high != NULL && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

int main() 
{
    int n;
    cout << "enter number of nodes: ";
    cin >> n;

    for (int i = 0; i <n; i++)
        insert();

    cout << "\nBefore sorting: \n";
    print();

    quickSort(head, tail);

    cout << "\nAfter sorting:\n ";
    print();

    return 0;
}
