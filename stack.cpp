#include <iostream>
using namespace std;
#define n 100
class stack
{
    int *arr;
    int counter;
public:
    stack()
    {
        arr = new int[n];
        counter = -1;
    }
    void push(int v)
    {
        if(counter == n-1)
        {
            cout<<"The stack has overflowed"<<endl;
            return;
        }
        counter++;
        arr[counter] = v;
    }
    void pop(void)
    {
        if(counter == -1)
        {
            cout<<"The stack has no elements"<<endl;
            return;
        }
        counter--;
    }
    
    int top(void)
    {
        if(counter==-1)
        {
            cout<<"The stack is empty"<<endl;
            return 0;
        }
        return arr[counter];
    }

    bool empty()
    {
        return (counter==-1);
    }
    int size()
    {
        return counter+1;
    }
};


int main()
{
    stack s;
    s.push(1);
    s.pop();
    s.push(5);
    s.push(574);
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    s.push(5);
    s.push(574);
    cout<<s.size()<<endl;

    return 0;
}