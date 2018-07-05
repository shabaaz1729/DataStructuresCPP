#include<iostream>
using namespace std;

//declaration of a node 
struct Node{
	int data;
	Node* link;
};
		 
int main()
{
	Node* A=NULL; //pointer to the first node

	Node* temp = (Node*) new Node(); 
	temp->data=34;
	temp->link=NULL;

	A=temp;

	cout<<(A->data)<<endl;

	return 0;
}