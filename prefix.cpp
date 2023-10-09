#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
int PrefixEvaluation(vector<string> s)
{
    int n, result;
    int n1, n2;
    stack<int> str;
    for (int i = s.size()- 1; i >= 0; i--)
    {
        if ((s[i] != "+") && (s[i] != "-") && (s[i] != "*") && (s[i] != "/") && (s[i] != "^"))
        {
            n = stoi(s[i]);
            str.push(n);
        }
        else if (s[i] == "+")
        {
            n1 = str.top();
            str.pop();
            n2 = str.top();
            str.pop();
            result = n1 + n2;
            str.push(result);
        }
        else if (s[i] == "-")
        {
            n1 = str.top();
            str.pop();
            n2 = str.top();
            str.pop();
            result = n1 - n2;
            str.push(result);
        }
        else if (s[i] == "*")
        {
            n1 = str.top();
            str.pop();
            n2 = str.top();
            str.pop();
            result = n1 * n2;
            str.push(result);
        }
        else if (s[i] == "/")
        {
            n1 = str.top();
            str.pop();
            n2 = str.top();
            str.pop();
            result = n1 / n2;
            str.push(result);
        }
        else if (s[i] == "^")
        {
            n1 = str.top();
            str.pop();
            n2 = str.top();
            str.pop();
            result = pow(n2,n1);
            str.push(result);
        }
    }
    n = str.top();
    str.pop();
    return n;
}
int main()
{
    vector<string> s;
    s.push_back("-");
    s.push_back("+");
    s.push_back("7");
    s.push_back("*");
    s.push_back("4");
    s.push_back("5");
    s.push_back("+");
    s.push_back("2");
    s.push_back("0");
    cout <<PrefixEvaluation(s);
    return 0;
}