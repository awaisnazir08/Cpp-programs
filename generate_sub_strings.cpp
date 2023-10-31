#include<iostream>
using namespace std;
void substrings(string s, string ans = "")
{
    if(s.empty())
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    substrings(s.substr(1),ans);
    substrings(s.substr(1), ans + ch);
}
int main()
{
    substrings("ABCD");
    return 0;
}