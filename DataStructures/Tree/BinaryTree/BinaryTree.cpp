#include "BinaryTree.h"
#include <limits.h>
#include <stdlib.h>
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


TreeNode* BinaryTree::LCA(TreeNode *root, int v1, int v2) {
    if (!root) return NULL;
    if (root->data == v1 || root->data == v2) return root;
    TreeNode *left = LCA(root->left, v1, v2);
    TreeNode *right = LCA(root->right, v1, v2);
    if (left && right) return root;
    else
        return left ? left : right;
}

/**
 * Printing level order spiral form
 * Algorithm:
 * 1) push root node in queue
 * 2) while queue is not empty do
 * 3) enqueue node from queue and print
 * 4) if left child exists 
 *    i) push left child in stack
 *    ii)pust the left and right child of this node in queue
 * 5) if right child exists
 *    i) push right child in stack
 *    ii) push the left and right child of this node in queue
 * 6) while stack is not empty display top node and pop
 * repeat 2-6 until queue items are not empty
 * T(n) = O(n^2)
 * S(n) = O(n)+O(m)
 */
void BinaryTree::levelOrderSpiral(TreeNode* root) {
  if (!root) return;
  queue<TreeNode*> q;
  stack<TreeNode*> s;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    cout<<node->data<<" ";
    q.pop();
    if (node->left) {
        s.push(node->left);
        if (node->left->left) q.push(node->left->left);
           if (node->left->right) q.push(node->left->right);
    }
    if (node->right) {
        s.push(node->right);
        if (node->right->left) q.push(node->right->left);
        if (node->right->right) q.push(node->right->right);
    }
    while (!s.empty()) {
      cout<<s.top()->data<<" ";
      s.pop();
    }
  }
 }

void BinaryTree::levelOrderSpiral2Stack(TreeNode *root) {
    if (!root) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            TreeNode *node = s1.top();
            cout<<node->data<<" ";
            s1.pop();

            if (node->left) s2.push(node->left);
            if (node->right) s2.push(node->right);
        }
        while (!s2.empty()) {
            TreeNode *node = s2.top();
            cout<<node->data<<" ";
            s2.pop();

            if(node->right) s1.push(node->right);
            if (node->left) s1.push(node->left);
        }
    }
}

/**
 * Uses sum(TreeNode*) to evalute if a given tree is sum tree
 * A tree is a sum tree if its root.data = sum(root.left) + sum(root.right)
 * also, its left and right child are sum tree
 * An empty tree is also a sum tree where in sum of their children
 * is 0.
 * Since, this uses sum which has O(n) time to caculate the sum
 * therefore, T(n) = for each node its subtree sum is evaluated
 * T(n) = O(n^2)
 */
bool BinaryTree::isSumTree(TreeNode *root) {
    if (!root || ((!root->left) && (!root->right))) return true;
    int lst, rst;
    lst = sum(root->left);
    rst = sum(root->right);
    if (root->data == lst + rst
     && isSumTree(root->left) && isSumTree(root->right)) return true;
    return false;
}

/**
 * Finds the sum of all the nodes in the tree
 * Algorithm
 * 1) if root does not exists return 0
 * 2) else return evaluate the sum of lst + get the root data 
 * + evaluate the sum of right sub tree
 * T(n) = O(n)
 */
int BinaryTree::sum(TreeNode *root) {
    if (!root) return 0;
    return sum(root->left) + root->data + sum(root->right);
}

int BinaryTree::toSumTree(TreeNode *root) {
    if (!root) return 0;

    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);
    return old_val + root->data;
}

bool isLeaf(TreeNode *node) {
    return !node && node->left == NULL && node->right == NULL;
}

/**
 * Checks if the given tree is sum tree or not 
 * 1) If a node is at the leaf node then the sum = value of the node
 * 2) If a node is no leaf node then sum = 2 * value of the node.
 */
bool BinaryTree::isSumTreeEfficient(TreeNode *root) {
    int lst, rst;
    if (!root || isLeaf(root)) return true;

    if (isSumTreeEfficient(root->left) && isSumTreeEfficient(root->right)) {
        if (root->left == NULL) lst = 0;
        else if (isLeaf(root->left)) lst = root->left->data;
        else lst = 2*root->left->data;

        if (root->right == NULL) rst = 0;
        else if (isLeaf(root->right)) rst = root->right->data;
        else rst = 2*root->right->data;
        return root->data == lst+rst;
    }
    return false;
}


int searchIn(int A[], int lo, int hi, int key) {
    for (int i = lo; i <= hi; ++i) if (A[i] == key) return i;
    return -1;
}

TreeNode* BinaryTree::buildTree(int inOrder[], int preOrder[], int lo, int hi) {
    static int preIndex = 0;
    if (lo > hi) return NULL;
    TreeNode *node = new TreeNode(preOrder[preIndex++]);
    if (lo == hi) return node;
    int inIndex = searchIn(inOrder, lo, hi, node->data);    
    if (inIndex == -1) exit(0);
    node->left = buildTree(inOrder, preOrder, lo, inIndex-1);
    node->right = buildTree(inOrder, preOrder, inIndex+1, hi);
    return node;
}

void BinaryTree::leftView(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    cout<<root->data<<" ";
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        if (front->left) {
            cout<<front->left->data<<" ";
            q.push(front->left);
        }
        if (front->right) q.push(front->right);
    }
}

void BinaryTree::rightView(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    cout<<root->data<<" ";
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        if (front->left) q.push(front->left);
        if (front->right) {
            cout<<front->right->data<<" ";
            q.push(front->right);
        }
    }
}