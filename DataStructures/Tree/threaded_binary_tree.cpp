#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
	bool isRightThreaded;
	TreeNode(int data_) : data(data_) {
		left = NULL;
		right = NULL;
		isRightThreaded = false;
	}
};

/**
 * Uses Recursion Stack
 * T(N) = O(N)
 * S(N) = O(N), stack
 */
void inorder(TreeNode *root) {
	if (!root) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

/**
 * T(N) = O(N)
 * S(N) = O(N), queue
 */
void buildQueue(TreeNode *root, queue<TreeNode*> *q) {
	if (!root) return;
	if (root->left) buildQueue(root->left, q);
	q->push(root);
	if (root->right) buildQueue(root->right, q);
}

/**
 * T(N) = O(N)
 * S(N) = O(1)
 */
TreeNode* leftMost(TreeNode *root) {
	if (!root) return NULL;
	while (root->left) root = root->left;
	return root;
}


/**
 * Algorithm:
 * 1) if left chikd exits call lst
 * 2) pop the left child simply
 * 3) if right child exists call rst
 * 4) if right child is null, assign the right 
 * child with front of the queue which will be inorder successor
 * 5) Set the isRightThreaded to true
 * T(N) = O(N)
 */
void convert(TreeNode *root, queue<TreeNode*> *q) {
	if  (!root) return;
	if (root->left) convert(root->left, q);
	q->pop(); // need to pop the node which is non root

	if (root->right) convert(root->right, q);
	else { // attach the inorder successor from the queue
		root->right = q->front();
		root->isRightThreaded = true;
	}
}

/**
 * Algorithm: 
 * 1) Find the leftmost in the given tree curr = leftMost(root)
 * 2) Do the following:
 * 3) print the data
 * 4) If isRightThread is true
 * 5) Update curr = curr->right
 * 6) else curr = leftMost(curr->right)
 * 7) repeat 2-6 untill curr != NULL
 * T(N) = O(N)
 * S(N) = O(1)
 */
void inorderThreaded(TreeNode *root) {
	if (!root) return;
	TreeNode *curr = leftMost(root);
	while (curr) {
		cout<<curr->data<<" ";
		if (curr->isRightThreaded) {
			curr = curr->right;
		} else {
			curr = leftMost(curr->right);
		}
	}
}


int main() {
	TreeNode *threadedTree = new TreeNode(1);
	threadedTree->left = new TreeNode(2);
	threadedTree->right = new TreeNode(3);
	threadedTree->left->left = new TreeNode(4);
	threadedTree->left->right = new TreeNode(5);

	// Printing inorder with stack/recursion
	inorder(threadedTree);

	cout<<"\nConverting into SingleThreaded\n";

	// converting the given tree into threadedTree
	queue<TreeNode*> q;
	buildQueue(threadedTree, &q);
	convert(threadedTree, &q);
	inorderThreaded(threadedTree);

	return 0;
}