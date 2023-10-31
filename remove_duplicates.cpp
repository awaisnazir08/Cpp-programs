#include<iostream>
#include<stack>
using namespace std;
// string removeDuplicate(string s)
// {
//     if(s.empty())
//     {
//         return "";
//     }
//     char ch = s[0];
//     string ans = removeDuplicate(s.substr(1));
//     if(ch == ans[0])
//     {
//         return ans;
//     }
//     return ch+ans;
// }
string removeDuplicates(string s)
{
    static string new_s;
    if(s.empty())
    {
        return "";
    }
    new_s += s[0];
    string result = "";
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] !=new_s[new_s.length()-1])
        {
            result +=s[i];
        }
    }
    removeDuplicates(result);
    return new_s;
}
int main()
{
    string s ={"7aaannnbbbccbbvvxsssw"};
    string str = removeDuplicates(s);
    for(int i = 0; i < str.size(); i++)
    {
        cout<<str[i];
    }
    return 0;
}