#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct Student{
    string name;
    int age;
    double gpa;
}s1;
int main(){
   s1.name ="Ali";
   s1.age=22;
   s1.gpa=3.9;
   cout<<"NAMe IS: "<<s1.name<<endl;
   cout<<"AGE IS: "<<s1.age<<endl;
   cout<<"GPA IS: "<<s1.gpa<<endl;
}