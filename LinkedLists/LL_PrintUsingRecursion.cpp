#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};


node* insert(node *head,int x)
{
	node *temp=new node();
	temp->data=x;
	temp->link=NULL;
	
	if(head==NULL)
	{	
		head=temp;
	}
	else
	{
		node *temp2,*temp1=head;
		while(temp1!=NULL)
		{
			temp2=temp1;
			temp1=temp1->link;
		}

		temp2->link=temp;
	}
	return head;
}

void print(node* head)
{
	if(head==NULL)
	{
		cout<<endl;
		return ;
	}
	cout<<head->data<<" ";
	print(head->link);
}

void printReverse(node* head)
{
	if(head==NULL)
	{
		cout<<endl;
		return;
	}
	printReverse(head->link);
	cout<<head->data<<" ";
}

int main()
{
	node* head=NULL;

	for(int i=1;i<100;i+=4)
		head=insert(head,i);

	print(head);
	printReverse(head);
	return 0;

}

