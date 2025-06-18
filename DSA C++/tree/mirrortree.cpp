#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

struct node{
    float data;
    node *left;
    node *right;
};

void insert(node *& root, float value){
        node* newnode=(node *)malloc(sizeof(node));
        newnode->data=value;
        newnode->left=NULL;
        newnode->right=NULL; 

    if(root==NULL)
    {
        root=newnode;
        return;
    }
    queue <node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(temp->left==NULL){
           temp->left=newnode;
           return;}
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right=newnode;
            return ;
        }
        else{
            q.push(temp->right);
        }
    }
}
void makemirror(node* root)
{
    if(root==NULL) return;
    node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    makemirror(root->left);
    makemirror(root->right);
} 
void preorder(node* root)
{
    if(root==NULL) return;
   
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n;
    cout<<"Enter the number of nodes in the tree: ";
    cin>>n;
    node*root=NULL;
    for(int i=0; i<n; i++)
    {
        float value;
        cout<<"Enter the value of node "<<i+1<<": ";
        cin>>value;
        insert(root,value);
    }
    cout<<"Inorder traversal of the original tree: ";
    preorder(root);
    cout<<endl;
    makemirror(root);
    cout<<"Inorder traversal of the mirror tree: ";
    preorder(root);
    cout<<endl;
    return 0;
}