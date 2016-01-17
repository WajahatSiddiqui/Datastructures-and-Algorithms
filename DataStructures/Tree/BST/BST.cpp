#include "BST.h"

TreeNode* BST::insert(TreeNode *root, int value) {
	if (!root) {
		TreeNode *node = new TreeNode(value);
		root = node;
	}

	if (value < root->data)
		root->left = insert(root->left, value);
	if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

bool BST::search(TreeNode *root, int value) {
	if (!root) return false;
	if (root->data == value) return true;

	if (value < root->data)
		return search(root->left, value);
	if (value > root->data)
		return search(root->right, value);
	return false;
}

void BST::inOrder(TreeNode *root) {
	if (!root) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

