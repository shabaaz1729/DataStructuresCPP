#include<iostream>
using namespace std;
#define MAX_SIZE 100

int A[MAX_SIZE];
int top=-1;

void Push(int x)
{
	if(top==MAX_SIZE-1)
	{
		cout<<"Stack Overflow\n";
		return;
	}

	A[++top]=x;
}

void Pop()
{
	if(top==-1)
	{
		cout<<"No element to pop\n";
		return;

	}
	top--;
}

int Top()
{
	return A[top];
}

void print()
{
	for(int i=top;i>=0;i--)
		cout<<A[i];
}

int main()
{
	Push(1);
	Push(2);
	Push(3);
	Push(4);
	Push(5);
	Pop();
	Push(-1);

	print();
	return 0;
}

