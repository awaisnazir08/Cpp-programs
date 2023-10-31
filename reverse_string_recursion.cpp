#include<iostream>
#include<string>
using namespace std;
void reverseString(string str)
{
    if(str.empty())
    {
        cout<<str;
        return;
    }
    reverseString(str.substr(1));
    cout<<str[0];
}
int main()
{
    reverseString("binod");
    return 0;
}