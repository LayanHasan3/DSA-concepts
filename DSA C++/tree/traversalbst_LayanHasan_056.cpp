#include <iostream>
using namespace std;

struct bstnode
{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};
bstnode * root=NULL;
// Insert function
bstnode* insert(bstnode* node, int value)
{
    if (node == NULL) {
        bstnode* temp=(bstnode *)malloc(sizeof(bstnode));
        temp->data = value;
        temp->lchild = NULL;
        temp->rchild = NULL;
        return temp;
    }
    if (value < node->data) {
        node->lchild = insert(node->lchild, value);
    }
    else {
        node->rchild = insert(node->rchild, value);
    }
    return node;
}

// Search function
bool search(bstnode* root, int value) {
    if (root == NULL) {
        return false;  
    }
    if (root->data == value) {
        return true;
    }
    if (value < root->data) {
        return search(root->lchild, value);  
    } else {
        return search(root->rchild, value); 
    }
}

// Find minimum node in the BST
bstnode* findMin(bstnode* node) {
    while (node->lchild != NULL) {
        node = node->lchild;
    }
    return node;
}

// Delete function
bstnode* deleteNode(bstnode* root, int value) {
    if (root == NULL) return root;
    
    if (value < root->data) {
        root->lchild = deleteNode(root->lchild, value);
    } else if (value > root->data) {
        root->rchild = deleteNode(root->rchild, value);
    } else {
        if (root->lchild == NULL) {
            bstnode* temp = root->rchild;
            free (root);
            return temp;
        } else if (root->rchild == NULL) {
            bstnode* temp = root->lchild;
            free (root);
            return temp;
        }
        bstnode* temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }
    return root;
}

// Traversal functions
void preOrder(bstnode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
void InOrder(bstnode* root){
    if(root!=NULL){
        InOrder(root->lchild);
        cout<<root->data<<" ";
        InOrder(root->rchild);
    }
}
void postOrder(bstnode* root){
    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        cout<<root->data<<" ";
    }
}

int main()
{
    bstnode* root = NULL; 
    root = insert(root, 200);  
    root = insert(root, 212); 
    root = insert(root, 202); 
    root = insert(root, 201);
    root = insert(root, 255); 
    root = insert(root, 197); 
    root = insert(root, 297);
    root = insert(root, 260); 
    root = insert(root, 210); 
    
    cout<<"Preorder Traversal of BST: ";
    preOrder(root);
    cout<<endl;
    cout<<"Inorder Traversal of BST: ";
    InOrder(root);
    cout<<endl;
    cout<<"Postorder Traversal of BST: ";
    postOrder(root);
    cout<<endl;
    
    int searchVal;
    cout << "Enter a value to search in the BST: ";
    cin >> searchVal;
    if (search(root, searchVal)) {
        cout << "Value " << searchVal << " found in the BST." << endl;
    } else {
        cout << "Value " << searchVal << " not found in the BST." << endl;
    }
    
    int deleteVal;
    cout << "Enter a value to delete from the BST: ";
    cin >> deleteVal;
    root = deleteNode(root, deleteVal);
    
    cout << "Inorder Traversal after deletion: ";
    InOrder(root);
    cout << endl;
    
    return 0;
}
