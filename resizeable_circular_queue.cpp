#include <iostream>
using namespace std;
class ResizableCircularQueue {
private:
    int *arr;
    int capacity;
    int front;
    int rear;

public:
    ResizableCircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~ResizableCircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            resize();
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
    }

    // Function to dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    // Function to get the element at the front of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return a sentinel value or throw an exception
        }
        return arr[front];
    }

    // Function to resize the array when it becomes full
    void resize() {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        int i = 0;
        while (front != rear) {
            newArr[i] = arr[front];
            front = (front + 1) % capacity;
            i++;
        }
        newArr[i] = arr[rear];
        front = 0;
        rear = i;
        capacity = newCapacity;

        delete[] arr;
        arr = newArr;
    }
};

int main() {
    ResizableCircularQueue queue(2);

    for (int i = 1; i <= 10; i++) {
        queue.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    std::cout << "Front element: " << queue.getFront() << std::endl;

    for (int i = 0; i < 5; i++) {
        queue.dequeue();
    }

    std::cout << "Front element: " << queue.getFront() << std::endl;

    return 0;
}
