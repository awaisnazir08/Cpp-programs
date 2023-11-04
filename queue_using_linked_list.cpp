#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int v)
    {
        this->data= v;
        this->next = nullptr;
    }
};
class queue
{
    node* front;
    node* back;
    public:
    queue()
    {
        // this->data = v;
        this->back= NULL;
        this->front = NULL;
    }
    void enqueue(int v)
    {
        node *n = new node(v);
        if(front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void dequeue()
    {
        if(front == NULL & back == NULL)
        {
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
        if(front == NULL)
        {
            back = NULL;
        }
    }

    int peek()
    {
        if(front == NULL)
        {
            cout<<"The queue is empty!"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if(front == NULL)
        {
            return 1;
        }
        return false;
    }
    bool isFull()
    {
        return false;
    }
};
int main()
{
    queue q1;
    q1.enqueue(5);
    cout<<q1.empty();
    q1.dequeue();
    cout<<q1.empty();
    return 0;
}