#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int data) {
    struct TreeNode *newTreeNode = new TreeNode();
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
}

void inorder_r(struct TreeNode* tree) {
    if (!tree) return;
    else {
        inorder_r(tree->left);
        cout<<tree->data<<" ";
        inorder_r(tree->right);
    }
}

void preorder_r(struct TreeNode* tree) {
    if (!tree) return;
    else {
        cout<<tree->data<<" ";
        preorder_r(tree->left);
        preorder_r(tree->right);
    }
}

void postorder_r(struct TreeNode* tree) {
    if (!tree) return;
    else {
        postorder_r(tree->left);
        postorder_r(tree->right);
        cout<<tree->data<<" ";
    }
}

int main() {
    struct TreeNode *tree;
    tree = newNode(4);
    tree->left = newNode(1);
    tree->left->left = newNode(8);
    tree->left->right = newNode(10);
    tree->right = newNode(9);
    tree->right->right = newNode(11);

    cout<<"Inorder: ";
    inorder_r(tree);
    cout<<"\nPreorder: ";
    preorder_r(tree);
    cout<<"\nPostorder: ";
    postorder_r(tree);
    cout<<endl;

    return 0;
}
