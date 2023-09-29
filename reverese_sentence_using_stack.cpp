#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    stack<string> s2;
    stack<char> s;
    string word;
    string a = "Hello, How are you doing?";
    // for (int i = 0; i < a.size(); i++)
    // {
    //     s.push(a[i]);
    // }
    // cout << s.size() << endl;
    // while (!s.empty())
    // {
    //     cout << s.top();
    //     s.pop();
    // }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != ' ')
        {
            word += a[i];
        }
        else
        {
            s2.push(word);
            s2.push(" ");
            word.clear();
        }

        if (i == a.size() - 1)
        {
            s2.push(word);
            word.clear();
        }
    }
    while (!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }
    return 0;
}