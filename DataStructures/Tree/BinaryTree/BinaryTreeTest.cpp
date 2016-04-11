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
	cout<<"Inorder Traversal: ";
	binaryTree->inOrder(tree);
	cout<<"\nInorderStack Traversal: ";
	binaryTree->inOrderStack(tree);
	cout<<"\nPreorder Traversal: ";
	binaryTree->preOrder(tree);
	cout<<"\nPostorder Traversal: ";
	binaryTree->postOrder(tree);
	cout<<"\nLevelorder Traversal: ";
	binaryTree->levelOrder(tree);
	cout<<"\nLevelorderQueue Traversal: ";
	binaryTree->levelOrderQueue(tree);
    cout<<"\nPrinting left view: ";
    binaryTree->leftView(tree);
    cout<<"\nPrinting right view: ";
    binaryTree->rightView(tree);
    cout<<"\nPrinting spiral using 1 queue and 1 stack: ";
    binaryTree->levelOrderSpiral(tree);
    cout<<"\nPrinting spiral using 2 stacks: ";
    binaryTree->levelOrderSpiral2Stack(tree);

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

    cout<<"\nSum of tree: "<<binaryTree->sum(tree)<<endl;

    /*cout<<"toSumTree(tree)\n";
    binaryTree->toSumTree(tree);
    binaryTree->inOrder(tree);*/

    TreeNode *sumTree = new TreeNode(26);
    sumTree->left = new TreeNode(10);
    sumTree->right = new TreeNode(3);
    sumTree->left->left = new TreeNode(6);
    sumTree->left->right = new TreeNode(4);
    sumTree->right->right = new TreeNode(3);
    cout<<"The given tree(sumTree) is: "<<binaryTree->isSumTree(sumTree)<<endl;
    cout<<"The given tree(sumTree) is: "<<binaryTree->isSumTreeEfficient(sumTree)<<endl;
    
    int inorder[] = {1, 5, 3, 4, 2};
    int preorder[] = {4, 5, 1, 3, 2};
    int treesize = sizeof(inorder)/sizeof(inorder[0]);
    TreeNode *newTree = binaryTree->buildTree(inorder, preorder, 0, treesize-1);
    cout<<"Building Binary Tree with inorder and preorder - Result\n";
    binaryTree->inOrder(newTree);
    cout<<endl;
    binaryTree->preOrder(newTree);
    TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(9);
        root->left->right = new TreeNode(6);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);
        root->right->left->left = new TreeNode(12);
        root->right->left->right = new TreeNode(7);
        root->left->right->left = new TreeNode(11);
        root->left->left->right = new TreeNode(10);
    cout<<"\nDiagonal View\n";
    binaryTree->diagonalView(root);
    cout<<"Computing the diagonal sum: \n";
    binaryTree->computeDiagonalSum(root);

    cout<<"Verticle view: \n";
    binaryTree->verticleView(root);

    cout<<"Top View: ";
    binaryTree->topView(root);
    delete binaryTree;
    return 0;	
}