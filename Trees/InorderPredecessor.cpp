#include<iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* lc;
	BstNode* rc;
};

BstNode* find(BstNode* root,int data)
{
	if(root==NULL)
		return NULL;
	else if(root->data == data)
		return root;
	else if(data < root->data)
		return find(root->lc,data);
	else 
		return find(root->rc,data);
}


BstNode* getPredecessor(BstNode* root,int data)
{
	BstNode* current = find(root,data);

	if(current == NULL)
		return NULL;

	// case 1 : if current has a left subtree

	if(current->lc != NULL)
	{
		BstNode* temp = current->lc;
		while(temp->rc != NULL)
			temp = temp->rc;
		return temp;
	}

	// case 2 : if current doesn't have a left subtree (Go to nearest ancestor for which given node is in right subtree)

	else
	{
		BstNode* predecessor = NULL;
		BstNode* ancestor = root;
		while(ancestor != current)
		{
			if(current->data > ancestor->data)
			{
				predecessor = ancestor;
				ancestor = ancestor->rc;
			}
			else
				ancestor = ancestor->lc;
		}
		return predecessor;
	}
}

