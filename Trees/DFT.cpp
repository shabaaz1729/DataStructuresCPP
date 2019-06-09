#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* lc;
	Node* rc;
};

// Depth First Traversal

void preOrder(Node* root)
{	
	if(root == NULL)
		return ;
	cout<<root->data<<" ";
	preOrder(root->lc);
	preOrder(root->rc);
}

void inOrder(Node* root)
{
	if(root == NULL)
		return ;
	inOrder(root->lc);
	cout<<root->data<<" ";
	inOrder(root->rc);
}

void postOrder()
{
	if(root==NULL)
		return ;
	postOrder(root->lc);
	postOrder(root->rc);
	cout<<root->data<<" ";
}

int main()
{
	
  	return 0;
}