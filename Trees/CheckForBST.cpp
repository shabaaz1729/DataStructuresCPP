//This is a C++ program to check if a given binary tree is a BST

struct Node
{
	int data;
	Node* left;
	Node* right;
};

bool isBST(Node* root,int min,int max)
{
	if(root==NULL)
		return true;

	if(root->data>min && root->data<max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max))
		return  true;

	return false;
}
