#include "BinaryTree.h"
#include <limits.h>
#include <queue>
#include <stack>


TreeNode* BinaryTree::getTree() {
 TreeNode *tree;
    tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left =  new TreeNode(-1);
    tree->right->right = new TreeNode(100);
    tree->left->left->left = new TreeNode(98);
    return tree;
}


bool BinaryTree::isMirror(TreeNode *tree1, TreeNode *tree2) {
	if (tree1 != NULL && tree2 != NULL) {
		return tree1->data == tree2->data
		&& isMirror(tree1->left, tree2->right)
		&& isMirror(tree1->right, tree2->left);
	} else {
		return tree1 == tree2;
	}
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
int BinaryTree::findMax(TreeNode *tree) {
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
int BinaryTree::findMin(TreeNode *tree) {
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

/**
 * Algorithm:
 * (1) check the element with the root, if equal the it is found
 * (2) else, recursively check the element in lst/rst
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
bool BinaryTree::search(TreeNode *tree, int data) {
    if (!tree) return false;
    if (data == tree->data) return true;
    else {
        return search(tree->left, data) || search(tree->right, data);
    }
    return false;
}

/**
 * Algorithm:
 * (1) calculate the size of lst and rst rescursively and add 1
 * for current node
 * T(n) = O(n)
 * S(n) = O(n) , stack
 */
 int BinaryTree::size(TreeNode *tree) {
    if (!tree) return 0;
    return size(tree->left) + 1 + size(tree->right);
}

// Mirrors the binary tree
// T(n) = O(n)
// S(n) = O(n) stack
TreeNode* BinaryTree::mirror(TreeNode *root) {
    if (!root) return NULL;
    else {
        mirror(root->left);
        mirror(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

/**
 * Compares the nodes data and structure of the tree
 * and matches the same 
 * Algorithm:
 * 1) Both the trees are empty return true
 * 2) If tree1, tree2 exists and 
 * 3) tree1->data == tree2->data and
 * 4) recursively check tree1->left == tree2->left
 * 5) recursively check tree1->right == tree2->right
 * 6) 2, 3, 4, 5 => return true
 * 7) return false;
 * T(n) = O(n)
 */
bool BinaryTree::isEqual(TreeNode *tree1, TreeNode *tree2) {
	if (!tree1 && !tree2) return true;
	if (tree1 && tree2 && tree1->data == tree2->data
		&& isEqual(tree1->left, tree2->left)
		&& isEqual(tree1->right, tree2->right)) return true;
	return false;	
}

int BinaryTree::height(TreeNode* tree) {
    if (!tree) return 0;
    else {
        int lh = height(tree->left);
        int rh = height(tree->right);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

/**
 * Print the data in the tree at the level if it is at 1
 * else recursively call with level-1
 * T(n) = O(n)
 */
void BinaryTree::levelOrder(TreeNode* tree, int level) {
    if (!tree) return;
    if (level == 1) cout<<tree->data<<" ";
    else if (level > 1) {
        levelOrder(tree->left, level-1);
        levelOrder(tree->right, level-1);
    }
}

/**
 * for 1 to 1 to h
 *     levelOrder(h)
 * T(n) = O(n^2)
 */
void BinaryTree::levelOrder(TreeNode* tree) {
	if (!tree) return;
	// get the height of the tree
	// and compute the data at each level
    int h = height(tree);
    for (int i = 1; i <= h; i++) {
        levelOrder(tree, i);
    }
}

/**
 * Print level order using queue
 * 1) Enqueue root node
 * 2) while(!q.empty()) 
 * 3) dequeue and print 
 * 4) If lst and rst exists push into the queue
 * 5) repeat 2-4 untill q is not empty
 * T(n) = O(n), n is the number of nodes in binary tree
 * S(n) = O(n), Queue
 */
void BinaryTree::levelOrderQueue(TreeNode *root) {
	if (!root) return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front();
		cout<<node->data<<" ";
		q.pop();
		if (node->left) q.push(node->left);
		if (node->right) q.push(node->right);
	}
}

/**
 * Visit the lst
 * Visit the root
 * Visit the rst
 * T(n) = O(n)
 * S(n) = O(n), stack
 */
void BinaryTree::inOrder(TreeNode* tree) {
    if (!tree) return;
    else {
        inOrder(tree->left);
        cout<<tree->data<<" ";
        inOrder(tree->right);
    }
}

/**
 * Visit the lst
 * Visit the root
 * Visit the rst
 * T(n) = O(n)
 * S(n) = O(n), stack
 */
void BinaryTree::inOrderStack(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    bool done = false;
    TreeNode *curr = root;
 	while(!done) {
 		if (curr != NULL) {
    		s.push(curr);
    		curr = curr->left;
    	} else if (curr == NULL && !s.empty()) {
    		curr = s.top();
    		cout<<curr->data<<" ";
    		s.pop();
    		curr = curr->right;
   		} else
   		done = true;
    }
}

/**
 * Visit the root
 * Visit the lst
 * Visit the rst
 * T(n) = O(n)
 * S(n) = O(n), stack
 */
void BinaryTree::preOrder(TreeNode* tree) {
    if (!tree) return;
    else {
        cout<<tree->data<<" ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

/**
 * Visit the lst
 * Visit the rst
 * Visit the root
 * T(n) = O(n)
 * S(n) = O(n), stack
 */
void BinaryTree::postOrder(TreeNode* tree) {
    if (!tree) return;
    else {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<<tree->data<<" ";
    }
}