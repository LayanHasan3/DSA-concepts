#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    else if(op=='*' || op=='/'){
        return 2;
    }
    else if(op=='^'){
        return 3;
    }
    return 0;
}
string infixtoPostfix(string expression){
    stack<char> operators;
    string postfix = "";
    for(char c: expression){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix+= c;
        }
    else if(c=='('){
        operators.push(c);
    }
    else if(c==')'){
        while(!operators.empty() && operators.top()!='('){
            postfix=postfix+c;
            operators.pop();
        }
        operators.pop();
    }
    else{
        while(!operators.empty() && precedence(operators.top())>=precedence(c) && c!='^'){
            postfix=postfix+c;
            operators.pop();
        }
        operators.push(c);
    }
}
    while(!operators.empty())
    {
        postfix=postfix+operators.top();
        operators.pop();
    }
    return postfix;
}
int main()
{
    string expression;
    cout<<"Enter the infix expression: ";
    getline(cin, expression);
    string postfix=infixtoPostfix(expression);
    cout<<"the postfix expression is: "<<postfix<<endl;
    return 0;
}