#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node * head = NULL;
void insert(int data){
    Node * ptr = (Node *)malloc(sizeof(Node));
    cout<<"Enter the data: ";
    cin>>ptr->data;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        Node * curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
    }
}
Node* middleElement(Node* head)
{
    Node*slow=head;
    Node*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void insertatindex(int val,int pos)//insert at specific index function
{
    if(pos<0)
    {
        cout<<"invalid position";
        return;
    }
    if(pos==0)
    {
      insert(val);
    return;
    }
    Node* temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}
void search()
{
    int tosearch;
    cout<<"Enter the element to search: ";
    cin>>tosearch;
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==tosearch){
            cout<<"searched element is found"<<endl;
            break;
        }
        else{
            curr=curr->next;
        }
    }
}
void print(){
    Node * curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" "<<endl;
        curr=curr->next;
    }
}
void Delete(){
    int todel;
    cout<<"Enter the element to delete: ";
    cin>>todel;
    if(todel==head->data){
        Node *temp=head;
        head=head->next;
        free(temp);
    }
    else{
        Node *curr= head->next;
        Node* prev=head;
        while(curr!=NULL){
            if(curr->data==todel){
                prev->next=curr->next;
                free(curr);
                break;
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
        }
    }
}
Node* reverselist(Node* head)
{
    Node*prev=NULL;
    Node*curr=head;
    Node*next=NULL;
    while(curr!=NUll)
    {
        next->curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        insert(i);
    }
    print();
    cout<<"new index: "<<endl;
    insertatindex(4,1);
    search();
    Delete();
    print();

    return 0;
}