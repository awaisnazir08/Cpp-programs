#include<iostream>
#include<vector>
using namespace std;
class Stack
{
    vector<char>v;
    public:

    void Push(char val)
    {
        v.push_back(val);
    }

    char Pop()
    {
        if(v.empty())
        {
            cout<<"The stack is empty!"<<endl;
        }
        else
        {
            char s = v.back();
            v.pop_back();
            return s;
        }
    }

    bool isEmpty()
    {
        return v.empty();
    }

    bool isFull()
    {
        return false;
    }
    
    void Clear()
    {
        v.clear();
    }

    char Peak()
    {
        return v.back();
    }

};
int main()
{
    vector<int> c={1,2,3};
    // c.clear();
    cout<<c.empty();
    return 0;
}