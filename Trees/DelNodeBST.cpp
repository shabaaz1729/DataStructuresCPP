#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node* lc;
	Node* rc;
};

int findMin(Node* root)
{
	if(root->lc == NULL)
		return root->data;
	return findMin(root->lc);
}

Node* deleteNode(Node* root,int value)
{
	if(root==NULL)
		return root;

	else if(value < root->data)
		root->lc = deleteNode(root->lc,value);

	else if(value > root->data)
		root->rc = deleteNode(root->rc,value);

	else
	{
		if(root->lc == NULL && root->rc == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}

		else if(root->lc == NULL)
		{
			Node* temp = root;
			root = root->rc;
			delete temp;
			return root;
		}

		else if(root->rc == NULL)
		{
			Node* temp = root;
			root = root->lc;
			delete temp;
			return root;
		}

		else
		{
			int min = findMin(root->rc);
			root->data = min;
			root->rc = deleteNode(root->rc,min);
			return root;
		}

	}
}

int main()
{
	
  	return 0;
}