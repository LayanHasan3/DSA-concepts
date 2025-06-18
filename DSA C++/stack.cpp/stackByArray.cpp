#include<iostream>
using namespace std;
int stack[10];
int top=0;
void push(int x)
{
    if (top==10)
      cout<<"Stack Overflow"<<endl;
    else{
      stack[top]=x;
      top++; 
    }  
}
int pop()
{
    if(top==0)
    {
      cout<<"stack Underflow"<<endl;
      return -1;
    }
    else
    {
        int x=stack[top-1];
        top--;
        return x;
    }
}
int main()
{
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);

    for(int i=0;i<top;i++)
    {
        cout<<stack[i]<<" ";
    }
    pop();
    cout<<endl;
    for(int i=0;i<top;i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
    push(120);
    for(int i=0;i<top;i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
    return 0;
}