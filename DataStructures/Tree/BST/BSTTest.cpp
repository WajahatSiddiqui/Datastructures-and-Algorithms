#include "BST.h"

int main() {
	BST *bst = new BST();
	TreeNode *root = NULL;
	root = bst->insert(root, 6);
	root = bst->insert(root, 5);
	root = bst->insert(root, 7);
	root = bst->insert(root, 10);
	root = bst->insert(root, 0);
	root = bst->insert(root, 4);
	root = bst->insert(root, -1);

	cout<<"Printing inorder traversal: ";
	bst->inOrder(root);
	cout<<endl;

	cout<<"Printing in the range (0, 7): \n";
	bst->printRange(root, 0 ,7);
	cout<<endl;
	cout<<"Printing Ceil from 0 to 15: ";
	for (int i = 0; i < 15; i++)
		cout<<bst->ceil(root, i)<<" ";
	cout<<endl;
	cout<<"Printing Floor from 0 to 15: ";
	for (int i = 0; i < 15; i++)
		cout<<bst->floor(root, i)<<" ";
	cout<<endl;
	cout<<"Maximum element: "<<bst->findMax(root)<<endl;
	cout<<"Minimum element: "<<bst->findMin(root)<<endl;

	cout<<"Searching for 4 in the tree\n";
	if (bst->search(root, 4)) {
		cout<<"Element 4 found\n";
	} else {
		cout<<"Element 4 not present in the BST\n";
	}

	cout<<"LCA(5, 4) = "<<bst->LCA(root, 5, 4)->data<<endl;

	cout<<"Deleting -1\n";
	bst->deleteNode(root, -1);
	bst->inOrder(root);
	cout<<endl;

	cout<<"Deleting 0\n";
	bst->deleteNode(root, 0);
	bst->inOrder(root);
	cout<<endl;

	cout<<"Deleting 6\n";
	bst->deleteNode(root, 6);
	bst->inOrder(root);
	cout<<endl;


	cout<<"Checking if binary tree is bst\n";
	TreeNode *binaryTree = new TreeNode(4);
	binaryTree->left = new TreeNode(2);
	binaryTree->right = new TreeNode(6);
	binaryTree->right->right = new TreeNode(100);
	bst->inOrder(binaryTree);
	cout<<endl;
	if (bst->isBinaryTreeBSTInorder(binaryTree)) {
		cout<<"It is BST\n";
	} else {
		cout<<"It is not BST\n";
	}
	cout<<"Checking if binary tree is not bst\n";
	TreeNode *nonBinaryTree = new TreeNode(4);
	nonBinaryTree->left = new TreeNode(10);
	nonBinaryTree->right = new TreeNode(-1);
	bst->inOrder(nonBinaryTree);
	cout<<endl;
	if (bst->isBinaryTreeBST(nonBinaryTree)) {
		cout<<"It is BST\n";
	} else {
		cout<<"It is not BST\n";
	}

	cout<<"Building a BST with the {1 2 3 4 5 ... 10}\n";
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	TreeNode *tree = bst->buildBST(A, sizeof(A)/sizeof(A[0]));
	cout<<"Printing inorder traversal\n";
	bst->inOrder(tree);
	cout<<endl;

	cout<<"Building a BST with the 1 2 3 4 5 as LinkedList \n";
	Node *list = new Node(1);
	list->next = new Node(2);
	list->next->next = new Node(3);
	list->next->next->next = new Node(4);
	list->next->next->next->next = new Node(5);
	TreeNode *treeLL = bst->buildBSTLL(list);
	cout<<"Printing inorder traversal\n";
	bst->inOrder(treeLL);
	cout<<endl;	

	delete bst;
	return 0;
}