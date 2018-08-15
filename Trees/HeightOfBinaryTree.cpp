// C++ code to find the height of a tree

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int FindHeight(Node* root)
{
	if(root==NULL)
		return -1;

	return max(FindHeight(root->left),FindHeight(root->right))+1;
}