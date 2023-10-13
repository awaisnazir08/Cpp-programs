#include <iostream>
#define N 100
using namespace std;
class Stack
{
    char v[N];
    int count;

public:
    Stack()
    {
        count = -1;
    }
    void Push(char val)
    {
        if (count <= N - 2)
        {
            count++;
            v[count] = val;
            return;
        }
        cout << "The stack has overflowed!" << endl;
    }

    char Pop()
    {
        if (count == -1)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {

            char s = v[count];
            if (count >= 0)
            {
                count--;
            }
            return s;
        }
    }

    bool isEmpty()
    {
        if (count == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        return count == N - 1;
    }

    void Clear()
    {
        count = -1;
    }

    char Peak()
    {
        if (count == -1)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            return v[count];
        }
    }
};

bool balancedParenthesis(string b)
{
    Stack s;
    for(int i = 0; i<b.size(); i++)
    {
        if(s.isEmpty())
        {
            s.Push(b[i]);
        }
        else if(b[i]=='{' || b[i]=='[' || b[i]=='(')
        {
            s.Push(b[i]);
        }
        else
        {
            switch (b[i])
            {
                case ')':
                if(s.Peak()=='(')
                {
                    s.Pop();
                    break;
                }
                else
                {
                    return false;
                }
                case '}':
                if(s.Peak()=='{')
                {
                    s.Pop();
                    break;
                }
                else
                {
                    return false;
                }
                                case ']':
                if(s.Peak()=='[')
                {
                    s.Pop();
                    break;
                }
                else{
                    return false;
                }
            }

        }
    }
    return true;
}
int main()
{
    string s = "1 + 2 *[ 3 * 3 + { 4 - 5 ( 6 ( 7 / 8 / 9 ) + 10 ) } - 11 + ( 12 * 8) / {13 + 13}] + 14";
    cout<<balancedParenthesis(s);
    return 0;
}