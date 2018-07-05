#include <iostream>
#include <stack>
using namespace std;

struct node
{
  int data;
  node* next;
};

node* head=NULL;

void makelist(int x)
{
  node* temp=new node();
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }

  node* temp1=head;
  while(temp1->next!=NULL)
    temp1=temp1->next;

  temp1->next=temp;

}

void print()
{
  node* temp=head;
  while(temp->next!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<temp->data<<endl;
}

void Reverse()
{
    stack<int> S;

    node* temp=head;
    while(temp!=NULL)
    {
      S.push(temp->data);
      temp=temp->next;
    }

    int x;
    temp=head;
    while(temp!=NULL)
    {
      x=S.top();
      S.pop();
      temp->data=x;
      temp=temp->next;
    }
}

int main()
{
  makelist(1);
  makelist(2);
  makelist(3);
  makelist(4);
  makelist(5);
  makelist(16);
  makelist(19);
  makelist(21);
  makelist(111);
  cout<<"List:\n";
  print();
  Reverse();
  cout<<"List After Reversing:\n";
  print();

  return 0;
}