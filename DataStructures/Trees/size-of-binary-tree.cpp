/**
 * Evaluate the size of given tree
 * Size is the number of nodes in the given binary tree
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
 * (1) calculate the size of lst and rst rescursively and add 1
 * for current node
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
static int sizeofTree(struct TreeNode *tree) {
    if (!tree) return 0;
    return sizeofTree(tree->left) + 1 + sizeofTree(tree->right);
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
    tree->left->left->left = newNode(98);

    cout<<"Size of given tree: "<<sizeofTree(tree)<<endl;
    return 0;
}
