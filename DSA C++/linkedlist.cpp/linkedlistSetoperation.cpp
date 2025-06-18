#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node * head = NULL;
void insert(Node ** head, int val)//** so that we can modidy it
{
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL){
    temp = temp->next;
    }
    temp->next = newnode;

}

void print(Node* head){
        while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
 
}
bool exists(Node* head, int val) {
    while (head != NULL) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}

Node* unionlist(Node* a, Node* b) {
    Node* result = NULL;

    while (a != NULL) {
        if (!exists(result, a->data)) {
            insert(&result, a->data);
        }
        a = a->next;
    }

    while (b != NULL) {
        if (!exists(result, b->data)) {
            insert(&result, b->data);
        }
        b = b->next;
    }

    return result;
}
Node* intersectionlist(Node* a, Node* b) {
    Node* result = NULL;
    Node* tempB;
    while (a != NULL) {
        tempB = b;
        while (tempB != NULL) {
            if (a->data == tempB->data) {
                insert(&result, a->data);
                break;
            }
            tempB = tempB->next;
        }
        a = a->next;
    }
    return result;
}
Node* differencelist(Node* a, Node* b) {
    Node* result = NULL;
    Node* tempB;
    bool found;
    while (a != NULL) {
        found = false;
        tempB = b;
        while (tempB != NULL) {
            if (a->data == tempB->data) {
                found = true;
                break;
            }
            tempB = tempB->next;
        }
        if (!found)
            insert(&result, a->data);
        a = a->next;
    }
    return result;
}
Node* mergeSorted(Node* a, Node* b) {
    Node* result = NULL;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            insert(&result, a->data);
            a = a->next;
        } else {
            insert(&result, b->data);
            b = b->next;
        }
    }
    while (a != NULL) {
        insert(&result, a->data);
        a = a->next;
    }
    while (b != NULL) {
        insert(&result, b->data);
        b = b->next;
    }
    return result;
}
Node* customizedInsert(Node* head, int val1, int val2) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == val1) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = val2;
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode;
        }
        curr = curr->next;
    }
    return head;
}
int main()
{
    Node* set1=NULL;
    Node* set2=NULL;
    
        insert(&set1, 1);
        insert(&set1, 3); 
        insert(&set1, 4); 
        insert(&set1, 7); 
        insert(&set1, 12);
        insert(&set2, 1); 
        insert(&set2, 5); 
        insert(&set2, 7); 
        insert(&set2, 9);
        cout<<"set1: ";
        print(set1);
        cout<<"set2: ";
        print(set2);
         Node* u = unionlist(set1, set2);
         cout << "Union (without duplicates): "; print(u);
          Node* inter = intersectionlist(set1, set2);
    cout << "Intersection: "; print(inter);
     Node* diff = differencelist(set1, set2);
    cout << "Difference (Set1 - Set2): "; print(diff);
        Node* sorted1 = NULL, *sorted2 = NULL;
    insert(&sorted1, 2); insert(&sorted1, 3); insert(&sorted1, 4); insert(&sorted1, 8); insert(&sorted1, 12);
    insert(&sorted2, 1); insert(&sorted2, 4); insert(&sorted2, 5); insert(&sorted2, 7); insert(&sorted2, 9);
    Node* merged = mergeSorted(sorted1, sorted2);
    cout << "Merged Sorted Lists: "; print(merged);
    Node* list = NULL;
    insert(&list, 2); insert(&list, 4); insert(&list, 3); insert(&list, 2);
    insert(&list, 8); insert(&list, 2); insert(&list, 5); insert(&list, 1); insert(&list, 2);
    list = customizedInsert(list, 2, 10);
    cout << "Customized Insert (2,10): "; print(list);

return 0;

}