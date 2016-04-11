#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

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

class BinaryTree {
public: 
	TreeNode *getNode(int data) {
	 	TreeNode *node = new TreeNode(data);
	 	if (!node) return NULL;
	 	return node;
	}
	TreeNode *getTree();

	// Traversal/Printing view
	void inOrder(TreeNode *root);
	void inOrderStack(TreeNode *root);
	void preOrder(TreeNode *root);
	void postOrder(TreeNode *root);
	void levelOrder(TreeNode *root);
	void levelOrderQueue(TreeNode *root);
	void levelOrderSpiral(TreeNode *root);
	void levelOrderSpiral2Stack(TreeNode *root);
	void topView(TreeNode *root);
	void bottomView(TreeNode *root);
	void leftView(TreeNode *root);
	void rightView(TreeNode *root);
	void diagonalView(TreeNode *root);
	void boundaryTraversal(TreeNode *root);
	void verticleView(TreeNode *root);


	// Dimensions
	int height(TreeNode *root);
	int width(TreeNode *root);
	int size(TreeNode *root);
	int diameter(TreeNode* root);
	int leafNodes(TreeNode *root);

	// Operations
	TreeNode* buildTree(int inOrder[], int preOrder[], int lo, int hi);
	TreeNode *mirror(TreeNode *root);
	TreeNode* LCA(TreeNode* root, int v1, int v2);
	TreeNode* convertToDoublyLL(TreeNode *root);
	int toSumTree(TreeNode *root);
	void computeDiagonalSum(TreeNode *root);

	bool isMirror(TreeNode *root1, TreeNode *root2);
	bool search(TreeNode *root, int data);
	bool isEqual(TreeNode *tree1, TreeNode *tree2);
	bool isLeavesAtSameLevel(TreeNode *root);
	bool isSumTree(TreeNode *root);
	bool isSumTreeEfficient(TreeNode *root);

	int findMax(TreeNode *root);
	int findMin(TreeNode *root);
	int sum(TreeNode *root);
	int distance(TreeNode *root, int key1, int key2);

	void deleteTree(TreeNode *root);
private:
	// Utility
	void levelOrder(TreeNode* tree, int level);
};


#endif // __BINARY_TREE_H__
