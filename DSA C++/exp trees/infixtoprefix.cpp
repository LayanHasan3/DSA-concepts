// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int precedence(char op)
{
    if(op=='^')return 3;
    if(op=='*'|| op=='/')return 2;
    if(op=='+'|| op=='-')return 1;
    return 0;
}
string infixtoprefix(string expression){
    reverse(expression.begin(), expression.end());
    
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]=='(')
        {
            expression[i]=')';
        }
        else if(expression[i]==')')
        {
            expression[i]='(';
        }
    }
    stack<char>operators;
    string result="";
    
    for(char& c:expression)
    {
        if((c>='a'&& c>='z')||(c>='A'&& c>='Z')||(c>='0'&& c>='9'))
        {
            result+=c;
        }
        else if(c=='(')
        {
            operators.push(c);
        }
        else if(c==')')
        {
            while(!operators.empty() && operators.top()!='(')
            {
                result+=operators.top();
                operators.pop();
            }
           if(!operators.empty()) operators.pop();
        }
        else{
            while(!operators.empty() && precedence(operators.top())>precedence(c) && c!='^')
            {
                result+=operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        }//for end
        while(!operators.empty()){
            result+=operators.top();
            operators.pop();
        }
    reverse(result.begin(),result.end());
    return result;
    }//func end
    int main()
    {
        string expression;
        cout<<"enter infix expression: ";
        getline(cin,expression);
        string prefix=infixtoprefix(expression);
        cout<<"the expression is: "<<prefix<<endl;
        return 0;
    }