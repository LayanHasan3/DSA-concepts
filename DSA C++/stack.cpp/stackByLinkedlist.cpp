#include<iostream>
using namespace std;
struct node{
    int data;
    node* next; 
};
node* top=NULL;
void push(int x){
    node * newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL)
    {
        cout<<"Stack Overflow";
        return;
    }
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}
int pop()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
        return -1;
    }
        int val=top->data;
        node * temp=top;
        top=top->next;
        free(temp);
        return val;
}
void display()
{
    node * curr=top;
    cout<<"Stack elements are: ";
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main()
{
    push(8);
    push(9);
    push(1);
    push(2);
    push(87);
    display();
    pop();
    display();
    return 0;
}