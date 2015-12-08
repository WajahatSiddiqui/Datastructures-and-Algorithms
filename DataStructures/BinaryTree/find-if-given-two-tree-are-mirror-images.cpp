#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

TreeNode *newNode(int data) {
    TreeNode *newTreeNode = new TreeNode();
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
}

bool isMirror(TreeNode *tree1, TreeNode *tree2) {
	if (tree1 != NULL && tree2 != NULL) {
		return tree1->data == tree2->data
		&& isMirror(tree1->left, tree2->right)
		&& isMirror(tree1->right, tree2->left);
	} else {
		return tree1 == tree2;
	}
}

int main()
{
	TreeNode *tree1 = newNode(5);
	tree1->left = newNode(1);
	tree1->right = newNode(2);
	
	TreeNode *tree2 = newNode(5);
	tree2->left = newNode(2);
	tree2->right = newNode(12);
	
	if (isMirror(tree1, tree2))
		cout<<"Tree1 and Tree2 are mirror of each other\n";
	else
		cout<<"Tree1 is not mirror of Tree2\n";
	
    return 0;
}
