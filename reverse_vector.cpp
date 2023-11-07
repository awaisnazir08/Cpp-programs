#include <iostream>
#include <vector>
using namespace std;

void reverseVector(vector<string>& v, int start, int end)
{
    if (start == end)
    {
        return;
    }
    string temp = v[start];
    v[start] = v[end];
    v[end] = temp;
    reverseVector(v, ++start, --end);
}

int main()
{
    vector<string> s;
    s.push_back("12");
    s.push_back("22");
    s.push_back("32");
    s.push_back("42");
    s.push_back("52");
    reverseVector(s,0,s.size()-1);
    for(int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }

    return 0;
}