#include <iostream>
#include <stack>
#include <string>
using namespace std;


void Reverse(string *s)
{
  string str=*s;
  stack<char> S;
  for(int i=0;i<str.length();i++)
    S.push(str[i]);

  for(int i=0;i<str.length();i++)
  {
    str[i]=S.top();
    S.pop();
  }

  *s=str;
}

int main()
{
  string s;
  cout<<"Enter a String:\n";
  cin>>s;
  Reverse(&s);
  cout<<"Reversed String:\n";
  cout<<s<<endl;
  return 0;
}