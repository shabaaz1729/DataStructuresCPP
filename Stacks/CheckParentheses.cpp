#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ArePair(char x ,char y)
{
    if(x=='{' && y=='}')
      return true;
    else if(x=='(' && y==')')
      return true;
    if(x=='[' && y==']')
      return true;

    return false;
}


bool checkparentheses(string str)
{
  int n=str.length();
  stack<char> S;
  for(int i=0;i<n;i++)
  {
    if(str[i]=='{' || str[i]=='(' || str[i]=='[')
      S.push(str[i]);
    else if(str[i]=='}' || str[i]==')' || str[i]==']')
    {
        if(S.empty() || !ArePair(S.top(),str[i]))
          return false;
        else
          S.pop();

    }
  }

  return S.empty() ? true:false;
}


int main()
{
  string s;
  cin>>s;
  
  if(checkparentheses(s))
    cout<<"balanced string\n";
  else
    cout<<"string is not balanced\n";
  return 0;
}