#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

node* head=NULL;

void Reverse(node* p)
{
	if(p->link==NULL)
	{
		head=p;
		return ;
	}

	Reverse(p->link);
	node* q = p->link;
	q->link=p;
	p->link=NULL;

}

void makelist(int x)
{
	node* temp=new node();
	node* last;
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

int main()
{
	for(int i=3;i<=100;i+=3)
	{
		makelist(i);
	}

	print();
	Reverse(head);
	print();
}