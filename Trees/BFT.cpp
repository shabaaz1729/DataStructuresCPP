// Code for Breadth first traversal of Tree

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void BFT(Node* root)
{
   if(root==NULL)
   {
   		cout<<"Empty Tree\n";
   		return;
   }
   
   queue<Node*> Q;

   Q.push(root);

   while(!Q.empty())
   {
   		Node* temp=Q.front();
   		cout<<temp->data<<" ";
   		if(root->left!=NULL)
   			Q.push(root->left);
   		if(root->right!=NULL)
   			Q.push(root->right);

   		Q.pop();
   }
}