#include <iostream>
#include <stack>
using namespace std;

bool Gprece(char c,char d)
{
    if((c=='*' || c=='/' || c=='^') && (d=='-' || d=='+'))
		return true;
	else if((c=='-' || c=='+') && (d=='-' || d=='+'))
		return true;
	else if((c=='*' || c=='/') && (d=='*' || d=='/'))
		return true;
	else if((c=='^') && (d=='*' || d=='/' || d=='^'))
	    return true;
	else
		return false;    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    string d="";
	    stack<char> S;
	    for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
                d+=s[i];
            
            else if(s[i]=='*' || s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='^')
            {
                while(!S.empty() && S.top()!='(' && Gprece(S.top(),s[i]))
                {
                    d+=S.top();
                    S.pop();
                }
                    S.push(s[i]);
            }
            
            else if(s[i]=='(')
                S.push(s[i]);
            
            else if(s[i]==')')
            {
                while(!S.empty() && S.top()!='(')
                {
                    d+=S.top();
                    S.pop();
                }
                
                S.pop();
            }
        }
        
        while(!S.empty())
        {
            d+=S.top();
            S.pop();
        }
        
        cout<<d<<endl;
	}
	return 0;
}
