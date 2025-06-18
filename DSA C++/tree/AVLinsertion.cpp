#include<iostream>
using namespace std;
struct node{
    int data;
    int height;
    node *left;
    node *right;
};
int height(node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}
int balancefactor(node* n)
{
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}
void updateheight(node* n)
{
    n->height= 1+max(height(n->left),height(n->right));
}
node * rotateRight(node* y){
    node * x= y->left;
    y->left=x->right;
    x->right=y;
    updateheight(y);
    updateheight(x);
    return x;
}
node * rotateLeft(node *x){
    node *y=x->right;
    x->right=y->left;
    y->left=x;
    updateheight(x);
    updateheight(y);
    return y;
}
node* insert(node* root, int data)
{
 if(root==NULL)
 {
      node* newnode=(node *)malloc(sizeof(node));
     newnode->data=data;
     newnode->height=1;
     newnode->left=NULL;
     newnode->right=NULL;
     return newnode;
 }
 if(data<root->data){
     root->left=insert(root->left,data);
 }
 else if(data>root->data){
     root->right=insert(root->right,data);
 }
 else{
     return root;
 }
 updateheight(root);
 int bf=balancefactor(root);
    if (bf > 1 && data < root->left->data) {
        return rotateRight(root);
    }

    // Right Right Case
    if (bf < -1 && data > root->right->data) {
        return rotateLeft(root);
    }

    // Left Right Case
    if (bf > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (bf < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}
void preorder(node* root) {
    if (root!=NULL) {
        
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    node* root = nullptr;
    int keys[] = {190, 180, 50, 10, 70, 170, 20, 80, 60, 18, 57, 77, 250, 211, 198, 200};

    // Insert all keys into the AVL tree
    for (int i = 0; i < 16; ++i) {
        root = insert(root, keys[i]);
    }

    cout << "Inorder traversal of AVL tree: ";
    preorder(root);
    cout << endl;

    return 0;
}