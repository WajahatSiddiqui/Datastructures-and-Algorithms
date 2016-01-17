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

	cout<<"Printing inorder traversal: ";
	bst->inOrder(root);
	cout<<endl;
	if (bst->search(root, 4)) {
		cout<<"Element 4 found\n";
	} else {
		cout<<"Element 4 not present in the BST\n";
	}
	delete bst;
	return 0;
}