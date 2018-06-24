#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* head=NULL;

void insert(int x)
{
	Node* temp=(Node*) new Node();
	temp->data=x;
	temp->link=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
}

void print()
{
	Node* temp=head;
	cout<<"List is:"<<endl;
	while(temp!=NULL)
	{
		cout<<(temp->data)<<" ";
		temp=temp->link;
	}
	cout<<endl;
}


int main()
{
	cout<<"Enter the size of linkedlist"<<endl;
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		insert(d);
	}

	print();
}