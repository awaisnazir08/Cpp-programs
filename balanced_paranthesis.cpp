#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool balancedParenthesis(string b)
{
    stack<char> s;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '{' || b[i] == '[' || b[i] == '(')
        {
            s.push(b[i]);
        }
        else
        {
            if(b[i] == ')' || b[i]=='}' || b[i]==']')
            {
                if(s.empty())
                {
                    return false;
                }
            }
            switch (b[i])
            {
            case ')':
                if (s.top() == '(')
                {
                    s.pop();
                    break;
                }
                else
                {
                    return false;
                }
            case '}':
                if (s.top() == '{')
                {
                    s.pop();
                    break;
                }
                else
                {
                    return false;
                }
            case ']':
                if (s.top() == '[')
                {
                    s.pop();
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (s.empty())
        return true;
    return false;
}
int main()
{
    string s = "1 + 2 *[ 3 * 3 + { 4 - 5 ( 6 ( 7 / 8 / 9 ) + 10 ) } - 11 + ( 12 * 8) / {13 + 13}] + 14";
    cout << balancedParenthesis(s);
    return 0;
}