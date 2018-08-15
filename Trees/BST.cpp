#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* insert(BstNode* root,int n)
{
	if(root==NULL)
	{
		BstNode* temp=new BstNode();
		temp->data=n;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}

	else if(n<=root->data)
	{
		root->left=insert(root->left,n);
		return root;
	}
	else
	{
		root->right=insert(root->right,n);
		return root;
	}

}

bool search(BstNode* root,int d)
{
	if(root==NULL)
		return false;

	else if(d==root->data)
		return true;

	else if(d<=root->data)
		return search(root->left,d);

	else 
		return search(root->right,d);

	return false;
}

int findMin(BstNode* root)
{
	if(root==NULL)
		return -1;
	while(root->left!=NULL)
		root=root->left;

	return root->data;
}

int findMax(BstNode* root)
{
	if(root==NULL)
		return -1;
	while(root->right!=NULL)
		root=root->right;

	return root->data;
}


int main()
{
	BstNode* root=NULL;
	root=insert(root,12);
	root=insert(root,34);
	root=insert(root,25);
	root=insert(root,11);
	root=insert(root,13);
	root=insert(root,9);
	root=insert(root,22);

	cout<<"Enter a number to search\n";
	int n;
	cin>>n;

	if(search(root,n))
		cout<<"Number Found\n";
	else
		cout<<"Number not Found\n";

	cout<<"Minimum number in the tree is "<<findMin(root)<<endl;
	
	cout<<"Maximum number in the tree is "<<findMax(root)<<endl;


	return 0;
}	
