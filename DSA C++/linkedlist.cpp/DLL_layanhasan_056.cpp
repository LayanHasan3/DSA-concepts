#include<iostream>
using namespace std;
struct node{
    int data;
    node * prev;
    node * next;
};
node * head=NULL;
node* tail=NULL;
void insert(){
    node* ptr= (node*)malloc(sizeof(node));
    cout<<"Enter the data: ";
    cin>>ptr->data;
    ptr->prev=NULL;
    ptr->next=NULL;
    
    if (head == NULL) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

// Function to delete a node by value
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

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }
    
    free(temp);
    cout << "Node deleted successfully!\n";
}

// Function to search for a node
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

// Function to display the list
void display() {
    node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insert();
    insert();
    insert();
    insert();
    display();
    search();
    Delete();
    display();

    return 0;
}
