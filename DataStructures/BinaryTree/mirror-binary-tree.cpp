//http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int data) {
    struct TreeNode *newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
}

// Mirrors the binary tree
// T(n) = O(n)
// S(n) = O(n) stack
static void mirror(struct TreeNode *root) {
    if (!root) return;
    else {
        mirror(root->left);
        mirror(root->right);
        struct TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

static void inorder(struct TreeNode *root) {
    if (!root) return;
    else {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main() {
    struct TreeNode *tree;
    tree = newNode(1);
    tree->left = newNode(3);
    tree->right = newNode(2);
    tree->right->left = newNode(5);
    tree->right->right = newNode(4);

    cout<<"Given tree: ";
    inorder(tree);
    mirror(tree);
    cout<<"\nMirror tree: ";
    inorder(tree);
    cout<<endl;
    return 0;
}
