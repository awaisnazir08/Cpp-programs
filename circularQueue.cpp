#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int front;
    int back;
    int *arr;
public:
    CircularQueue()
    {
        front = back = -1;
        arr = new int[100];
    }
    ~CircularQueue()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return front == -1 && back == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (back + 1) % 100 == front;
    }
    void enqueue(int v)
    {
        if (back == -1 && front == -1)
        {
            back = front = 0;
            arr[back] = v;
        }
        else if ((back + 1) % 100 == front)
        {
            cout << "The queue is full!" << endl;
        }
        else
        {
            back = (back + 1) % 100;
            arr[back] = v;
        }
    }
    void dequeue()
    {
        if (back == -1 && front == -1)
        {
            cout << "The queue is empty!" << endl;
        }
        else if (back == front)
        {
            back = front = -1;
        }
        else
        {
            front = (front + 1) % 100;
        }
    }
    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return a sentinel value or throw an exception
        }
        return arr[front];
    }
};
int main()
{

    return 0;
}