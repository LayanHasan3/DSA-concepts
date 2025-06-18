#include<iostream>
using namespace std;
 int Queue[5];
 int front=-1, rear=-1;
 void enqueue(int value)
 {

    if(rear==4)
    {
        cout<<"Queue is full"<<endl;    
    }
    else{
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear++;
        }
        Queue[rear]=value;
    }
 }
 void dequeue()
 {
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
 }
    void display()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else{
            for(int i=front;i<=rear;i++)
            {
                cout<<Queue[i]<<" ";
            }
            cout<<endl;
        }
    }
int main()
{
    enqueue(3);
    enqueue(10);
    enqueue(-1);
    display();
    dequeue();
    display();
    enqueue(0);
    enqueue(1);
    enqueue(5);
    display();
}
