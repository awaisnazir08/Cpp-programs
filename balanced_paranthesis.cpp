#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool balancedParenthesis(string b)
{
    stack<char>s;
    for(int i = 0; i<b.size(); i++)
    {
        if(s.empty())
        {
            s.push(b[i]);
        }
        else if(b[i]=='{' || b[i]=='[' || b[i]=='(')
        {
            s.push(b[i]);
        }
        else
        {
            switch (b[i])
            {
                case ')':
                if(s.top()=='(')
                {
                    s.pop();
                    break;
                }
                else
                {
                    return false;
                }
                case '}':
                if(s.top()=='{')
                {
                    s.pop();
                    break;
                }
                else
                {
                    return false;
                }
                                case ']':
                if(s.top()=='[')
                {
                    s.pop();
                    break;
                }
                else{
                    return false;
                }
            }

        }
    }
    return true;
}
int main()
{
    string s = "{[({()}])]}";
    cout<<balancedParenthesis(s);
    return 0;
}