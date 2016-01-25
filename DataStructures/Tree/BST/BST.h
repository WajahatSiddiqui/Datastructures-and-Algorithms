#ifndef __BST_H__
#define __BST_H__
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
	TreeNode(int _data) : data(_data) {
		left = NULL;
		right = NULL;
	}
};

struct Node {
	int data;
	Node *next;
	Node() : next(NULL) {}
	Node(int data_) : data(data_) {
		next = NULL;
	}
};

class BST {
public:
	TreeNode* insert(TreeNode* root, int data);
	TreeNode* deleteNode(TreeNode* root, int datat);


	// Traversal
	void inOrder(TreeNode* root);

	// Opeations
	bool search(TreeNode* root, int key);
	int findMin(TreeNode* root);
	int findMax(TreeNode* root);
	TreeNode* buildBST(int A[], int size);
	TreeNode* buildBSTLL(Node* root);
	bool isBinaryTreeBST(TreeNode* root);
	bool isBinaryTreeBSTInorder(TreeNode *root);
	TreeNode* LCA(TreeNode* root, int v1, int v2);
	TreeNode* convertBinaryTreeToBST(TreeNode *root);
	int ceil(TreeNode* root, int value);
	int floor(TreeNode* root, int value);
	TreeNode* mergeWithLimitedSpace(TreeNode *bst1, TreeNode *bst2);
	TreeNode* mergeBalancedBST(TreeNode *balancedBST1, TreeNode *balancedBST2);
	int findKSmallest(TreeNode *bst);
	int inOrderPredessor(TreeNode *root);
	int inOrderSuccessor(TreeNode *root);

};

#endif // __BST_H__