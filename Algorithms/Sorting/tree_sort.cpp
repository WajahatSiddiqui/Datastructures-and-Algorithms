/**
 *  Tree Sorts
 *  Sort a sequence of input using Binary Search Tree
 *  by continuously inserting the elements in BST and
 *  then printing them in inorder traversal
 **/

 #include <iostream>
 using namespace std;

 struct TreeNode {
 	int data, count;
 	TreeNode *left, *right;
 	TreeNode(int data_) : data(data_) {
 		count = 0;
 		left = NULL;
 		right = NULL;
 	}
 };

 TreeNode* insert(TreeNode *root, int data) {
 	TreeNode *node = new TreeNode(data);
 	if (!root) root = node;
 	if (data == root->data) root->count++;
 	if (data < root->data) root->left = insert(root->left, data);
 	if (data > root->data) root->right = insert(root->right, data);

 	return root;
 }

 void inorder(TreeNode *root) {
 	if (!root) return;
 	inorder(root->left);
 	if (root->count > 1) {
 		while (root->count--) cout<<root->data<<" ";
 	} else
 	cout<<root->data<<" ";
 	inorder(root->right);
 }

 void tree_sort(int A[], int size) {
 	TreeNode *tree = NULL;

 	for (int i = 0; i < size; i++) {
 		tree = insert(tree, A[i]);
 	}

 	inorder(tree);
 }

 int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<"\nTree Sorted Array: \n";
	tree_sort(A, size);	
	cout<<endl;
	return 0;
}
