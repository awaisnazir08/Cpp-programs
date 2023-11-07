#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;
    queue<int> q2;

public:
    void push(int v)
    {
        q.push(v); 
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "The stack is empty!" << endl;
        }
        int size = q.size() - 1;
        for (int i = 0; i < size; i++)
        {
            q2.push(q.front());
            q.pop();
        }
        q.pop();
        while (!q2.empty())
        {
            q.push(q2.front());
            q2.pop();
        }
    }

    int top()
    {
        if (!q.empty())
            return q.back();
        else
            cout << "The stack is empty!" << endl;
        return -1;
    }

    bool empty()
    {
        return q.empty();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    return 0;
}