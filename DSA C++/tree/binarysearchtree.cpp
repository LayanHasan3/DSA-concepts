#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct bstnode{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};
bstnode* root=NULL;
void insert(int value){
    bstnode *ptr=(bstnode*)malloc(sizeof(bstnode));
    ptr->data=value;
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    if(root==NULL){
        root=ptr;
    }
    else{
        bstnode *curr=root;
        bstnode *parent=NULL;
        while(curr!=NULL){
            parent=curr;
            if(value<curr->data){
                curr=curr->lchild;
            }
            else{
                curr=curr->rchild;
            }
        }
        if(value<parent->data){
            parent->lchild=ptr;
        }
        else{
            parent->rchild=ptr;
        }
    }
}
void preOrder(bstnode* root){
    if(root!=NULL){
        cout<<root->data<<endl;
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
void InOrder(bstnode* root){
    if(root!=NULL){
        preOrder(root->lchild);
        cout<<root->data<<endl;
        preOrder(root->rchild);
    }
}
void postOrder(bstnode* root){
    if(root!=NULL){
        preOrder(root->lchild);
        preOrder(root->rchild);
        cout<<root->data<<endl;
    }
}
int main()
{
    insert(10);
    insert(5);
    insert(15);
    insert(8);
    insert(3);
    insert(12);
    insert(18);
    cout<<"Binary Search Tree created successfully"<<endl;
    cout<<"Preorder Traversal"<<endl;
    preOrder(root);
    cout<<"Inorder Traversal"<<endl;
    InOrder(root);
    cout<<"Postorder Traversal"<<endl;
    postOrder(root);
    return 0;
}