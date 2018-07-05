#include<iostream>
using namespace std;

struct node 
{
	int data;
	node* link;
};

node* head=NULL;
node* last;

void insert(int x)
{
	node* temp = new node();
	temp->data=x;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		last=temp;
	}
	else
	{
		last->link=temp;
		last=temp;
	}

}

void print()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}

void DeleteAtN(int n)
{
	node* temp=head;
	if(n==1)
	{
		temp=head;
		head=temp->link;
		delete temp;
		return;
	}
	for(int i=1;i<n-1;i++)
	{
		temp=temp->link;
	}
	node* temp1=temp->link;
	temp->link=temp1->link;
	delete temp1;
}

int main()
{
	insert(1);
	insert(25);
	insert(125);
	insert(126);
	insert(256);
	insert(468);
	print();
	DeleteAtN(4);
	print();
}