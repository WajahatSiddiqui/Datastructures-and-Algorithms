/**
 * Search a given element in a given binary tree
 * Uses Recursion
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

static TreeNode* newNode(int data) {
    struct TreeNode *newTreeNode = new struct TreeNode();
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

/**
 * Algorithm:
 * (1) check the element with the root, if equal the it is found
 * (2) else, recursively check the element in lst/rst
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
static bool isAvailable(struct TreeNode *tree, int data) {
    if (!tree) return false;
    if (data == tree->data) return true;
    else {
        return isAvailable(tree->left, data) || isAvailable(tree->right, data);
    }
    return false;
}

int main() {
    struct TreeNode *tree;
    tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->right->left =  newNode(-1);
    tree->right->right = newNode(100);

    int element;
    cout<<"Enter an element from given binary tree: ";
    cin>>element;
    if (isAvailable(tree, element))
        cout<<element<<" found in given tree\n";
    else
        cout<<element<<" does not exists\n";
    return 0;
}
