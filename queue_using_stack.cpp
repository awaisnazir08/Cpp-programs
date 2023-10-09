#include <iostream>
using namespace std;
#include <stack>

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int v)
    {
        s1.push(v);
    }
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "The queue is empty!" << endl;
            return 0;
        }
        else if (!s1.empty())
        {
            int temp;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            temp = s2.top();
            s2.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return temp;
        }
    }

    // int peek()
    // {
    //     if(s1.empty())
    //     {
    //         cout<<"The queue is empty!"<<endl;
    //         return 0;
    //     }
    //     else
    //     {
    //         return s1.top();
    //     }
    // }
    bool isempty()
    {
        return s1.empty();
    }
};
int main()
{
    queue q1;
    q1.enqueue(5);
    q1.enqueue(7);
    q1.enqueue(9);
    cout<<q1.dequeue()<<endl;
    cout<<q1.isempty();
    return 0;
}