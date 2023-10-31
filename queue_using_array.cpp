#include <iostream>
#include<string>
using namespace std;
#define N 100
template <typename T>
class Queue
{
    T *arr;
    int front;
    int back;
    int count;

public:
    Queue()
    {
        arr = new T[N];
        front = back = -1;
    }
    ~Queue()
    {
        delete [] T;
    }
    void Enqueue(T val)
    {
        if (back == N - 1)
        {
            cout << "The queue is full!" << endl;
            return;
        }
        else if (front == -1 && back == -1)
        {
            front = back = 0;
            arr[back] = val;
        }
        else
        {
            back++;
            arr[back] = val;
        }
    }
    T Dequeue()
    {
        if (front == -1 && back == -1)
        {
            cout << "The queue is empty!" << endl;
            return -1;
        }
        else if (front == back)
        {
            T temp = arr[back];
            front = back = -1;
            return temp;
        }
        else
        {
            T temp = arr[front];
            front++;
            return temp;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && back == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (back == N - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Clear()
    {
        front = -1;
        back = -1;
    }
    T firstElement()
    {
        if (front == -1 && back == -1)
        {
            cout << "The queue is empty!" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

class Patient
{
    static int Id;
    Queue<int> patient_id;
    Queue<string> patient_name;
public:
    Patient()
    {
        Id++;
    }
    void RegisterPatient()
    {
        
    }
    void ServePatient()
    {
    }

    void CancelAll()
    {
    }

    void CanDoctorGoHome()
    {
    }

    void ShowAllPatients()
    {
    }
};

int Patient::Id = 0;
int main()
{

    return 0;
}