#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
};

TreeNode *insert(TreeNode *root, int value) {
	if (!root) {
		TreeNode *node = new TreeNode();
		node->data = value;
		node->left = NULL;
		node->right = NULL;
		root = node;
	}

	if (value < root->data)
		root->left = insert(root->left, value);
	if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

bool search(TreeNode *root, int value) {
	if (!root) return false;
	if (root->data == value) return true;

	if (value < root->data)
		return search(root->left, value);
	if (value > root->data)
		return search(root->right, value);
}

void inorder(TreeNode *root) {
	if (!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main() {
	TreeNode *root = NULL;
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 4);

	inorder(root);
	if (search(root, 4)) {
		cout<<"Element 4 found\n";
	} else {
		cout<<"Element 4 not present in the BST\n";
	}
	return 0;
}