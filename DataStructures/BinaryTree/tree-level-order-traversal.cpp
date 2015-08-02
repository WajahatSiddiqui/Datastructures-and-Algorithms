#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

static struct TreeNode* newNode(int data) {
    struct TreeNode* newTreeNode = new struct TreeNode();
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

static int getHeight(struct TreeNode* tree) {
    if (!tree) return 0;
    else {
        int lh = getHeight(tree->left);
        int rh = getHeight(tree->right);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

static void levelOrder(struct TreeNode* tree, int level) {
    if (!tree) return;
    if (level == 1) cout<<tree->data<<" ";
    else if (level > 1) {
        levelOrder(tree->left, level-1);
        levelOrder(tree->right, level-1);
    }
}

static void levelOrder(struct TreeNode* tree) {
    int h = getHeight(tree);
    for (int i = 1; i <= h; i++) {
        levelOrder(tree, i);
    }
}

int main() {
    struct TreeNode *tree;
    tree = newNode(1);
    tree->left = newNode(2);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->right = newNode(3);

    levelOrder(tree);
    return 0;
}

