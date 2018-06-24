#include <iostream>
#include <algorihtm>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* head=NULL;
Node* last;

void insert(int x)
{
	Node* temp = new Node();
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

/*

void insert(int x)
{
	node* temp=head;
	while(temp!=NULL)
	{
		temp1=temp;
		temp=temp->link;
	}

	node* temp2=new node();
	temp2->data=x;
	temp2->link=NULL;
	temp1->link=temp2;
}

*/

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