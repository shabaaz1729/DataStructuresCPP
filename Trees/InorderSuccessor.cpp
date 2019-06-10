#include<iostream>
using namespace  std;

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

// Get Successor

BstNode* getSuccesor(BstNode* root,int data)
{
	BstNode* current = find(root,data);

	if(current == NULL)
		return NULL;
	
	// case 1 : if right subtree of cuurent is not NULL

	if(current->rc!=NULL)
	{
		BstNode* temp = current->rc;
		while(temp->lc!=NULL)
			temp = temp->lc;
		return temp;
	}

	// case 2 : No right subtree of current 

	else
	{
		BstNode* successor = NULL;
		BstNode* ancestor = root;

		while(ancestor != current)
		{
			if(current->data < ancestor->data)
			{
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right
		}

		return successor;

	}


}
