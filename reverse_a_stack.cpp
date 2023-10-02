#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &s, int v)
{
    if(s.empty())
    {
        s.push(v);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s,v);
    s.push(temp);
}
 void reverseStack(stack<int> & s)
 {
    if(s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,temp);
 }
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}