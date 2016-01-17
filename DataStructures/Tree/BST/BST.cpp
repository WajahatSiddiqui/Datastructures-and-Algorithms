#include "BST.h"
#include <limits.h>

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

// Iterative version.
/*int BST::findMin(TreeNode* root) {
	TreeNode *curr = root;
	while (curr->left) {
		curr = curr->left;
	}
	return curr->data;
}

int BST::findMax(TreeNode* root) {
	TreeNode *curr = root;
	while (curr->right) {
		curr = curr->right;
	}
	return curr->data;
}*/

int BST::findMin(TreeNode *root) {
	int min = INT_MAX;
	if (!root) return min;
	if (!root->left) min = root->data;
	else return findMin(root->left);
	return min;
}

int BST::findMax(TreeNode *root) {
	int max = INT_MIN;
	if (!root) return max;
	if (!root->right) max = root->data;
	else return findMax(root->right);
	return max;
}

/**
 * For each node check if the
 * 1) if root's data is < min(lst) return false
 * 2) if root's data is > max(rst) return false
 * 3) recursively check lst and rst
 * T(n) = O(n)+O(n)
 */
bool BST::isBinaryTreeBST(TreeNode* root) {
	if (!root) return true;
	if ((root->left && root->data < findMin(root->left))
	 || (root->right && root->data > findMax(root->right))) return false;

	if(!isBinaryTreeBST(root->left) || !isBinaryTreeBST(root->right)) return false;

	return true;
}

bool BST::isBinaryTreeBSTInorder(TreeNode *root) {
	static int prev = INT_MIN;
	if (!root) return true;
	// traverse the tree in inorder fashion and keep track of prev node
	if (!isBinaryTreeBSTInorder(root->left)) return false;

	if (root->data <= prev) return false;
	prev = root->data;

	return isBinaryTreeBSTInorder(root->right);

}

/**
 * Algorithm:
 * 1) If left > right that means mid has exceeded hence there is
 * no child so return NULL
 * 2) if left == right => add A[left] and return the node
 * 3) Divide the array into two sub halves and recursively
 * mid = left + (right-left)/2
 * build the BST where in lst = left, mid-1 and rst = mid+1, right
 */
TreeNode* buildBSTUtil(int A[], int left, int right) {
	if (left > right) return NULL;
	TreeNode *node = new TreeNode(0);
	if (left == right) {
		node->data = A[left];
		return node;
	} else if (left < right) {
		int mid = left + (right - left)/2;
		node->data = A[mid];
		node->left = buildBSTUtil(A, left, mid-1);
		node->right = buildBSTUtil(A, mid+1, right);
	}
	return node;
}

/**
 * Builds a BST based on sorted array
 */
TreeNode* BST::buildBST(int A[], int size) {
	return buildBSTUtil(A, 0, size-1);
}
