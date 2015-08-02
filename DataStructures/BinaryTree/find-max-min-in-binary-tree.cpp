/**
 * Find Max and Min element in a given binary tree
 * Uses Recursion
 */
#include<iostream>
#include <limits.h>
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
 * (1) Initialize max to INT_MIN
 * (2) get the max value from lst, rst
 * (3) if lst > rst => max = lst, else max = rst
 * (4) if max < root => max = root
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
static int findMax(struct TreeNode *tree) {
    int max = INT_MIN, lst, rst;
    if (!tree) return max;
    lst = findMax(tree->left);
    rst = findMax(tree->right);
    if (lst > rst)
        max = lst;
    else
        max = rst;
    if (max < tree->data)
        max = tree->data;

    return max;
}

/**
 * Algorithm:
 * (1) Initialize min to INT_MAX
 * (2) get the min values from lst, rst
 * (3) if lst < rst => min = lst, else min = rst
 * (4) if min > root => min = root
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
static int findMin(struct TreeNode *tree) {
    int min = INT_MAX, lst, rst;
    if (!tree) return min;
    lst = findMin(tree->left);
    rst = findMin(tree->right);

    if (lst < rst)
        min = lst;
    else
        min = rst;
    if (min > tree->data)
        min = tree->data;
    return min;
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

    cout<<"Max element in the given tree: "<<findMax(tree)<<endl;
    cout<<"Min element in the given tree: "<<findMin(tree)<<endl;
    return 0;
}
