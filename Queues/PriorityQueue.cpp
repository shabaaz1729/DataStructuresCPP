#include <iostream>
using namespace std;

struct Node
{
	int data;
	int priority;
	Node* link;
};

Node *head=NULL;

bool isEmpty()
{
	if(head==NULL)
		return true;
	return false;
}

void pop()
{
	if(head == NULL)
		return;
	Node* temp = head;
	head = temp->link;
	delete temp;
}

void push(int d, int p)
{
	Node* temp = new Node();
	temp->data = d;
	temp->priority = p;
	temp->link = NULL;

	Node* start = head;

	if(head == NULL)
	{
		head = temp;
		return;
	}

	if(p > head->priority)
	{
		temp->link = head;
		head = temp;
		return;
	}

	while(p < start->link->priority && start->link != NULL)
		start = start->link;
	
	temp->link = start->link;
	start->link = temp;
}

void print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
}

int main()
{
	push(23,12);
	push(34,43);
	push(45,30);
	push(56,35);
	print();
}