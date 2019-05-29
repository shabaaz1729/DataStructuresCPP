#include<iostream>
# define MAX 10
using namespace std;


int Q[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
	if(front==-1 && rear==-1)
		return true;
	return false;
}

void enqueue(int d)
{
	if((rear+1) % MAX == front)
	{
		cout<<"Queue is full\n";
		return ; 
	}

	if(isEmpty())
	{
		front++;
		rear++;
		Q[rear] = d;
		return ;
	}

	rear = ++rear % MAX ;
	Q[rear] = d;

}

void dequeue()
{
	if(isEmpty())
		cout<<"Queue is empty\n";

	else if(front == rear)
	{
		front = -1;
		rear = -1;
	}

	else
		front = front++ % MAX;
}

void print()
{
	if(isEmpty())
		cout<<"Queue is empty\n";

	else if(front==rear)
		cout<<Q[rear]<<endl;

	else
	{
		int i = front;
		while(i != rear)
		{
			cout<<Q[i]<<" ";
			i = (i+1) % MAX;
		}
		cout<<Q[i]<<endl;
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
	dequeue();
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	dequeue();
	enqueue(10);
	enqueue(11);
	print();

	return 0;
}