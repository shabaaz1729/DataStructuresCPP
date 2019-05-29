#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node *FRONT = NULL, *REAR = NULL;

bool isEmpty()
{
	if(FRONT == NULL && REAR == NULL)
		return true;
	return false;
}

void enqueue(int d)
{
	if(FRONT == NULL && REAR == NULL)
	{
		Node *temp = new Node();
		temp->data = d;
		temp->link = NULL;
		FRONT = temp;
		REAR = temp; 
	}
	else
	{
		Node* temp = new Node();
		temp->data = d;
		temp->link = NULL;
		REAR->link = temp;
		REAR = temp;
	}

}

void dequeue()
{
	if(isEmpty())
		cout<<"Queue is empty\n";
	else
	{
		Node* temp = FRONT;
		FRONT = temp->link;
		delete temp;
	}
}

void print()
{
	Node* temp = FRONT;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	dequeue();
	enqueue(8);
	enqueue(9);
	enqueue(10);
	enqueue(11);

	print();
	return 0;
}