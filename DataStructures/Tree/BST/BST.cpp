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

TreeNode* BST::minNode(TreeNode *root) {
	if (!root) return NULL;
	TreeNode *curr = root;
	while (curr->left) {
		curr = curr->left;
	}
	return curr;
}

/**
 * There are 3 cases:
 * 1. Node to be deleted is leaf
 * 2. Node to be deleted has left/right child
 * 3. Node to be deleted has both left and right child exists.
 * Algorithm:
 * Search for the key where it exists in the tree and find the node to delete
 * if the node has left child as null replace the node with right and delete
 * if the node has right child as null, replace the node with left and delete
 * if both child exists, find the inorder successor (min in rst) and replace 
 * with the node and delete the node (min->data)
 */
TreeNode* BST::deleteNode(TreeNode *root, int value) {
	if (!root) return root;
	if (value < root->data) {
		root->left = deleteNode(root->left, value);
	} else if (value > root->data) {
		root->right = deleteNode(root->right, value);
	} else {
		if (root->left == NULL) {
			TreeNode *tmp = root->right;
			delete root;
			return tmp;
		} else if (root->right == NULL) {
			TreeNode *tmp = root->left;
			delete root;
			return tmp;
		}

		TreeNode *min = minNode(root->right);
		root->data = min->data;
		root->right = deleteNode(root->right, min->data);
	}
	return root;
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


TreeNode* buildBSTLLUtil(Node* head, int left, int right) {
	if (!head) return NULL;
	if (left > right) return NULL;
	TreeNode *node = new TreeNode(0);
	if (left == right) {
		int pos = left;
		Node *curr = head;
		while (pos-- && curr) {
			curr = curr->next;
		}
		node->data = curr->data;
		return node;
	} else if (left < right) {
		int mid = left + (right-left)/2;
		int pos = mid;
		Node *curr = head;
		while (pos-- && curr) {
			curr = curr->next;
		}
		node->data = curr->data;
		node->left = buildBSTLLUtil(head, left, mid-1);
		node->right = buildBSTLLUtil(head, mid+1, right);
	}
	return node;
}

int sizeofLL(Node *head) {
	if (!head) return 0;
	int count = 0;
	Node *curr = head;
	while (curr) {
		count++;
		curr = curr->next;
	}
	return count;
}

/**
 * Builds a BST based on the linked list head position/
 */
TreeNode* BST::buildBSTLL(Node* head) {
	int size = sizeofLL(head);
	return buildBSTLLUtil(head, 0, size-1);
}


TreeNode* BST::LCA(TreeNode *root, int v1, int v2) {
	if (!root) return NULL;

	// Keys in the LST are less than the root 
	if (root->data > v1 && root->data > v2)
		return LCA(root->left, v1, v2);

	// Keys in the RST are greater than the root
	if (root->data < v1 && root->data < v2)
		return LCA(root->right, v1, v2);

	return root;
}

void BST::printRange(TreeNode *root, int k1, int k2) {
	if (!root) return;
	printRange(root->left, k1, k2);
	if (root->data >= k1 && root->data <= k2) {
		cout<<root->data<<" ";
	}
	printRange(root->right, k1, k2);
}