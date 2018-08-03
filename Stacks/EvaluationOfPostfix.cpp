#include<iostream>
#include<string>
#include<stack>
using namespace std;

int cal(int x,int y,char c)
{
	if(c=='+')
		return x+y;
	else if(c=='-')
		return x-y;
	else if(c=='*')
		return x*y;
	else if(c=='/')
		return x/y;
}

int evaluate(string str)
{
	stack<int> S;
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			int x=str[i]-'0';
			S.push(x);
		}
		else
		{
			int op2=S.top(); S.pop();
			int op1=S.top(); S.pop();
			int res=cal(op1,op2,str[i]);
			S.push(res);
		}
	}

	return S.top();
}

int main()
{
	string s="12*34*+5-";
	int val=evaluate(s);
	cout<<val<<endl;
	return 0;
}
