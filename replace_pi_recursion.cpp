#include<iostream>
#include<string>
using namespace std;
string replacePI(string str)
{
    if(str.empty())
    {
        return "";
    }
    if(str[0]=='p' && str[1] =='i' )
    {
        str = "3.14" + replacePI(str.substr(2));
    }
    
    str = str[0] +  replacePI(str.substr(1));
    return str;

}
int main()
{
    string str = {"erwepifsppidsfpippipifew"};
    str = replacePI(str);
    for(int i = 0; i < str.size(); i++)
    {
        cout<<str[i];
    }
    return 0;
}