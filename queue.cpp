#include<iostream>
#include<list>
// #include<queue>
#define n 100
using namespace std;
class queue{
    int *arr;
    int back;
    int front;
    public:
    queue(){
        arr = new int(n);
        this->back = -1;
        this->front = -1; 
    }
    ~queue()
    {
        delete [] arr;
    }
    void enqueue(int v)
    {
        if(front == -1)
        {
            front ++;
        }
        if(back== n-1)
        {
            cout<<"Queue overflowed"<<endl;
            return;
        }
        back++;
        arr[back] = v;
    }
    void dequeue()
    {
        if(front ==-1 || front>back)
        {
            cout<<"The queue is empty"<<endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if(front ==-1 || front > back)
        {
            cout<<"The queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if(front == -1 || back<front)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    // queue<int> q;
    
    // list<int> a;

    return 0;
}