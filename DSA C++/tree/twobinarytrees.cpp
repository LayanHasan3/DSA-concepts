#include <iostream>
#include <cstdlib> // for malloc
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Insert into BST (creates node if needed)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = val;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Check if trees are equal
bool areEqual(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return (a->data == b->data) &&
           areEqual(a->left, b->left) &&
           areEqual(a->right, b->right);
}

// Check if trees have the same structure
bool sameStructure(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return sameStructure(a->left, b->left) &&
           sameStructure(a->right, b->right);
}

// Print in descending order
void printDescending(Node* root) {
    if (!root) return;
    printDescending(root->right);
    cout << root->data << " ";
    printDescending(root->left);
}

int main() {
    // Tree 1
    Node* tree1 = nullptr;
    tree1 = insert(tree1, 40);
    tree1 = insert(tree1, 20);
    tree1 = insert(tree1, 60);

    // Tree 2
    Node* tree2 = nullptr;
    tree2 = insert(tree2, 40);
    tree2 = insert(tree2, 20);
    tree2 = insert(tree2, 65); // Different from tree1

    // Comparison
    cout << "Are trees equal? " << (areEqual(tree1, tree2) ? "Yes" : "No") << endl;
    cout << "Do trees have same structure? " << (sameStructure(tree1, tree2) ? "Yes" : "No") << endl;

    // Print in descending order
    cout << "Tree 1 in descending order: ";
    printDescending(tree1);
    cout << endl;

    cout << "Tree 2 in descending order: ";
    printDescending(tree2);
    cout << endl;

    return 0;
}
