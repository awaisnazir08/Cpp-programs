#include <iostream>
#include <vector>
using namespace std;
#include <stack>

int checkPrecedence(string s)
{
    if (s == "+" || s == "-")
    {
        return 1;
    }
    else if (s == "*" || s == "/")
    {
        return 2;
    }
    else if (s == "^")
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
vector<string> infinixToPostfix(vector<string> str)
{
    stack<string> s;
    vector<string> result;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] != "+") && (str[i] != "-") && (str[i] != "*") && (str[i] != "/") && (str[i] != "^") && (str[i] != "(") && (str[i] != ")"))
        {
            result.push_back(str[i]);
        }
        else if (str[i] == "(")
        {
            s.push(str[i]);
        }
        else if (str[i] == ")")
        {
            while ((!s.empty()) && s.top() != "(")
            {
                result.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while ((!s.empty()) && (checkPrecedence(str[i]) <= checkPrecedence(s.top())))
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty())
    {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}
int main()
{
    vector<string> my_string;
    vector<string> result;
    my_string.push_back("89");
    my_string.push_back("+");
    my_string.push_back("6");
    my_string.push_back("*");
    my_string.push_back("(");
    my_string.push_back("4");
    my_string.push_back("-");
    my_string.push_back("5");
    my_string.push_back(")");
    my_string.push_back("/");
    my_string.push_back("8");

    result = infinixToPostfix(my_string);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }

    return 0;
}