#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <string>
#include<math.h>
int postPrefixEvaluation(vector<string> s)
{
    int n, result;
    int n1, n2;
    stack<int> str;
    for (int i = 0; i < s.size(); i++)
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
            result = n2 - n1;
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
            result = n2 / n1;
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
    s.push_back("4");
    s.push_back("6");
    s.push_back("+");
    s.push_back("2");
    s.push_back("/");
    s.push_back("5");
    s.push_back("*");
    s.push_back("7");
    s.push_back("+");
    cout << postPrefixEvaluation(s);
    return 0;
}