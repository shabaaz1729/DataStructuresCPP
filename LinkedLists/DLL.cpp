#include <iostream>
using namespace std;

struct node
{
	int data;
	node* prev;
	node* next;
};

node* head=NULL;

void InsertAtHead(int x)
{
	node *temp=new node();
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp; 	
}

void print(node* temp)
{
	if(temp==NULL)
	{
		cout<<endl;
		return;
	}
	cout<<temp->data<<" ";
	print(temp->next);
}

int main() {
	
	InsertAtHead(1);
	InsertAtHead(2);
	InsertAtHead(3);
	InsertAtHead(4);
	InsertAtHead(5);
	InsertAtHead(6);
	print(head);
	return 0;
}