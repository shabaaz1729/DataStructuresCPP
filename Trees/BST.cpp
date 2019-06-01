#include<iostream>
#include<algorithm>
using namespace std;

struct BstNode
{
	int data;
	BstNode* lc;
	BstNode* rc;
};

BstNode* root = NULL;

BstNode* insert(BstNode* root, int d)
{
	if(root==NULL)
	{
		BstNode* temp = new BstNode();
		temp->data = d;
		temp->lc = NULL;
		temp->rc = NULL;
		root = temp;
	}

	else if(d <= root->data)
		root->lc = insert(root->lc,d);

	else
		root->rc = insert(root->rc,d);

	return root;
}

bool isFound(BstNode* root, int d)
{
	if(root == NULL)
		return false;

	else if(root->data == d)
		return true;

	else if(d < root->data)
		return isFound(root->lc, d);
	
	else 
		return isFound(root->rc, d);
}

int findMin(BstNode* root)
{
	if(root->lc == NULL)
		return root->data;

	return findMin(root->lc);
}

int findMax(BstNode* root)
{
	if(root->rc == NULL)
		return root->data;

	return findMax(root->rc);
}

int findHeight(BstNode* root)
{
	if(root==NULL)
		return -1;

	return max(findHeight(root->lc),findHeight(root->rc))+1 ;
}

int main()
{
	root = insert(root,50);
	root = insert(root,76);
	root = insert(root,21);
	root = insert(root,4);
	root = insert(root,32);
	root = insert(root,64);
	root = insert(root,15);
	root = insert(root,52);
	root = insert(root,14);
	root = insert(root,100);
	root = insert(root,83);
	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,70);
	root = insert(root,87);
	root = insert(root,80);

	if(isFound(root,200))
		cout<<"87 is found\n";

	if(!isFound(root,4))
		cout<<"4 is not found\n";

	cout<<"Min element in the tree is "<<findMin(root)<<endl;
	cout<<"Max element in the tree is "<<findMax(root)<<endl;

	cout<<"Height of the tree is "<<findHeight(root)<<endl;

  	return 0;
}