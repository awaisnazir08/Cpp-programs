#include <iostream>
using namespace std;
string move_to_end(string s, char x)
{
    static string letter, final;
    if (s.empty())
    {
        return "";
    }
    if (s[0] == x)
    {
        letter += x;
    }
    else
    {
        final += s[0];
    }
    move_to_end(s.substr(1), x);

    return final + letter;
}
int main()
{
    string s = "dafafeadfafjwe";
    s = move_to_end(s, 'a');
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    return 0;
}