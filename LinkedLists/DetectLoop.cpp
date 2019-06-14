#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

Node* head = NULL;

void createlist(int d)
{
	if(head==NULL)
	{
		Node* temp = new Node();
		temp->data = d;
		temp->link = NULL;
		head = temp;
		return ;
	}

	Node* temp = head;
	while(temp->link != NULL)
		temp = temp->link;

	Node* temp1 = new Node();
	temp1->data = d;
	temp1->link = NULL;

	temp->link = temp1;

}

// version 1

bool detectLoop(Node* head)
{
	Node *temp1 = head, *temp2 = head;

	while(temp1 && temp2 && temp2->link)
	{
		temp1 = temp1->link;
		temp2 = temp2->link->link;
		if(temp1 == temp2)
			return true;
	}
	return false;

}

// version 2

bool detectLoop(Node* head)
{
	Node* temp = head;
	unordered_set<Node*> s;

	while(temp->link != NULL)
	{
		if(s.find(temp) == s.end())
		{
			s.insert(temp);
			temp = temp->link;
		}
		else
			return true;
	}

	return false;
}

int main()
{
	for(int i=0;i<10;i++)
		createlist(i);

	if(detectLoop(head) == true)
		cout<<"The linked list has a loop\n";
	else
		cout<<"The linked list doesn't have loop\n";

	return 0;
}