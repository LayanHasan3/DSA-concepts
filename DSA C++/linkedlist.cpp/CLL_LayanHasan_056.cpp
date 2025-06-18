#include<iostream>
using namespace std;
struct node{
    int data;
    node * next;
};
node * head= NULL;
void insert(){
    node * ptr=(node*)malloc(sizeof(node));
    cout<<"Enter the data: ";
    cin>>ptr->data;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }
    else{
        node * curr= head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=ptr;
        ptr->next=head;
    }
}
void search(){
    int key;
    cout<<"Enter the key you want to search: "<<endl;
    cin>>key;
    node * curr=head;
    do{
        if(curr->data==key){
            cout<<"Key found"<<endl;
            break;  
        }
        curr=curr->next;
    }
    while(curr!=head);
}
void Delete(){
    int key;
    cout<<"Enter the key you want to delete: "<<endl;
    cin>>key;
    node * curr=head;
    node * prev=NULL;
    do{
        if(curr->data==key){
            prev->next=curr->next;
            free(curr);
            break;
        }
        prev=curr;
        curr=curr->next;
    }
    while(curr!=head);
}
void print(){
    node * curr=head;
    do{
        cout<<curr->data<<" "<<endl;
        curr=curr->next;
    }
    while(curr!=head);
}
int main(){
    insert();
    insert();
    insert();
    insert();
    print();
    search();
    Delete();
    print();
    return 0;
}