#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool Gprec(char c,char d)
{
	if((d=='-' || d=='+') && (c=='*' || c=='/'))
		return true;
	else if((c=='-' || c=='+') && (d=='-' || d=='+'))
		return true;
	else if((c=='*' || c=='/') && (d=='*' || d=='/'))
		return true;
	else
		return false;
}	

int main()
{
	string str="2+3*4-5*6";
	string d="";
	stack<char> S;
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
			d+=str[i];
		else
		{
			if(S.empty())
				S.push(str[i]);
			else
			{
				while(Gprec(S.top(),str[i]))
				{
					d+=S.top();
					S.pop();	
					if(S.empty())
						break;
				}

				S.push(str[i]);
			}
		}
	}
	while(!S.empty())
	{
		d+=S.top();
		S.pop();
	}

	cout<<d<<endl;
	return 0;
}
