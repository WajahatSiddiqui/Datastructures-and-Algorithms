#include "BinaryTree.h"

int main() {
	BinaryTree *binaryTree = new BinaryTree();

	TreeNode *tree1 = new TreeNode(5);
	tree1->left = new TreeNode(1);
	tree1->right = new TreeNode(2);
	
	TreeNode *tree2 = new TreeNode(5);
	tree2->left = new TreeNode(2);
	tree2->right = new TreeNode(1);
	
	if (binaryTree->isMirror(tree1, tree2))
		cout<<"Tree1 and Tree2 are mirror of each other\n";
	else
		cout<<"Tree1 is not mirror of Tree2\n";

	TreeNode *tree = binaryTree->getTree();
	cout<<"Minimum value in tree is: "<<binaryTree->findMin(tree)<<endl;
	cout<<"Maximum value in tree is: "<<binaryTree->findMax(tree)<<endl;
	cout<<"Height of the tree is: "<<binaryTree->height(tree)<<endl;
	cout<<"Size of tree is: "<<binaryTree->size(tree)<<endl;
	cout<<"Inorder Traversal\n";
	binaryTree->inOrder(tree);
	cout<<"\nInorderStack Traversal\n";
	binaryTree->inOrderStack(tree);
	cout<<"\nPreorder Traversal \n";
	binaryTree->preOrder(tree);
	cout<<"\nPostorder Traversal \n";
	binaryTree->postOrder(tree);
	cout<<"\nLevelorder Traversal \n";
	binaryTree->levelOrder(tree);
	cout<<"\nLevelorderQueue Traversal \n";
	binaryTree->levelOrderQueue(tree);

	cout<<"\n Searching -1 in tree\n";
	if (binaryTree->search(tree, -1))
        cout<<"-1 found in given tree\n";
    else
        cout<<"-1 does not exists\n";

    cout<<"Mirroring tree\n";
    TreeNode *mirrorTree = binaryTree->mirror(tree);
    binaryTree->inOrder(mirrorTree);

    cout<<"\nChecking equality\n";
    if (binaryTree->isEqual(tree1, tree1)) {
    	cout<<"Equal\n";
    } else {
    	cout<<"Not Equal\n";
    }

    if (binaryTree->isEqual(tree1, mirrorTree)) {
    	cout<<"Equal\n";
    } else {
    	cout<<"Not Equal\n";
    }

    TreeNode *lcaTree = new TreeNode(4);
    lcaTree->left = new TreeNode(2);
    lcaTree->right = new TreeNode(7);
    lcaTree->left->left = new TreeNode(1);
    lcaTree->left->right = new TreeNode(3);
    lcaTree->right->left = new TreeNode(6);

    TreeNode *lcaNode = binaryTree->LCA(lcaTree, 1, 6);
    cout<<"LCA(lcaTree, 1, 6) = "<<lcaNode->data<<endl;

    TreeNode *loSpiral = new TreeNode(10);
    loSpiral->left = new TreeNode(5);
    loSpiral->right = new TreeNode(14);
    loSpiral->left->left = new TreeNode(2);
    loSpiral->left->right = new TreeNode(7);
    loSpiral->right->left = new TreeNode(11);
    loSpiral->right->right = new TreeNode(20);
    cout<<"Printing spiral using 1 queue and 1 stack\n";
    binaryTree->levelOrderSpiral(loSpiral);
    cout<<"\nPrinting spiral using 2 stacks\n";
    binaryTree->levelOrderSpiral2Stack(loSpiral);
    
    delete binaryTree;
    return 0;	
}