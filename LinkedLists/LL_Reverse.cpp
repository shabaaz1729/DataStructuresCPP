#include<iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

node* head=NULL;

void Reverse()
{
	node *current=head,*prev=NULL,*next;

	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	head=prev;
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
	Reverse();
	print();
}