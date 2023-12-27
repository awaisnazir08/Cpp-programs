#include <iostream>
#include <vector>
using namespace std;

//helping function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//class to create a binary minimum heap using arrays
class BinaryMinHeap
{
    //private heap array and some of the helper functions which are also private
    vector<int> heap;

    //to find the position of the parent node
    int parent(int position)
    {
        return position / 2;
    }

    //to find the position of the left child
    int leftChild(int position)
    {
        return position * 2;
    }

    //to find the position of the right child
    int rightChild(int position)
    {
        return (position * 2) + 1;
    }

    //function that builds the heap array in a way such that the heap properties are maintained
    void buildHeap()
    {
        int p = heap.size() - 1;
        // int t = size(); 
        //while the parent is greater than its child, swap the elements
        while (p >= 1 && heap[parent(p)] > heap[p])
        {
            //swap the elements if the parent is greater than any child node
            swap(heap[parent(p)], heap[p]);
            p = parent(p);
        }
    }

public:
    //constructor
    BinaryMinHeap()
    {
        heap.push_back(-1);
    }

    // Function to check if the heap is empty
    bool isEmpty()
    {
        return size() == 0;
    }

    // Function to get the number of elements in the heap
    int size()
    {
        return heap.size() - 1; // Excluding the placeholder at index 0
    }

    // Function to insert a number into the heap
    void push(int value)
    {
        heap.push_back(value);
        buildHeap();
    }

    // Function to get the minimum element without removing it
    int top()
    {
        if (isEmpty())
        {
            cerr << "Heap is empty\n";
            return -1; // Return a sentinel value
        }
        return heap[1];
    }

    // Function to remove and return the minimum element
    int pop()
    {
        //if the heap is empty
        if (isEmpty())
        {
            cerr << "Heap is empty\n";
            return -1;
        }
        //storing the lowest root node to be returned and popped into a variable
        int returnMinimumValue = heap[1];
        //putting the last leaf node in the root node
        heap[1] = heap[size()];
        //popping the last leaf node
        heap.pop_back();
        int minIndex = 1;
        int i = minIndex;
        //loop to adjust the root node in its appropriate position according to its value
        while (true)
        {
            //getting the left child index
            int left = leftChild(minIndex);
            
            //getting the right child index
            int right = rightChild(minIndex);
            if (left < size() && heap[left] < heap[minIndex])
            {
                minIndex = left;
            }

            //assigning the minimum index to the child with the lower value
            if (right < size() && heap[right] < heap[minIndex])
            {
                minIndex = right;
            }

            //if the parent is smaller than its all childs(at most 2), then the loop breaks, else it swaps and goes down
            if (i != minIndex)
            {
                swap(heap[i], heap[minIndex]);
                i = minIndex;
            }
            else
            {
                break; // Break the loop if the heap property is restored
            }
        }
        //returning the popped value
        return returnMinimumValue;
    }

    //function to get the height of the heap
    int height()
    {
        //finding the height using the array child and parent concept!
        int h = 0;
        int n = size();
        while (n > 0)
        {
            //getting the parents, and increasing the height variable by one
            n /= 2;
            h++;
        }
        return h;
    }
    //function to build the heap from an array
    void buildHeapfromArray(const vector<int>& array)
    {
        //initializing an empty array
        heap = {0};
        for(int element: array)
        {
            //pushing into the heap
            push(element);
        }
        cout<<"The heap has successfully been built..!!"<<endl;
    }


    //function to print the heap
    void printHeap()
    {
        cout<<"Heap array: "<<endl;
        int i = 0;
        for(int element: heap)
        {
            if (i==0)
            {
                i++;
                continue;
            }
            cout<<element<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    //initializing an object of the binary heap class
    BinaryMinHeap minHeap;
    //pushing some random values into the heap
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(9);
    minHeap.push(5);
    //elements are pushed in this order: 3, 1, 4, 9, 5
    cout << "Heap after pushing elements...(elements are pushed in this order: 3, 1, 4, 9, 5) "<<endl;
    minHeap.printHeap();

    cout << "Is heap empty? " << (minHeap.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Heap size: " << minHeap.size() << "\n";
    cout << "Heap height: " << minHeap.height() << "\n";

    cout << "Top element: " << minHeap.top() << "\n";

    minHeap.pop();
    cout << "Heap after popping the top element... "<<endl;
    minHeap.printHeap();

    cout<<"Now popping all the elements from the heap..."<<endl;
    while(!minHeap.isEmpty())
    {
        minHeap.pop();
    }

    cout << "Is heap empty? " << (minHeap.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Heap size: " << minHeap.size() << "\n";
    cout << "Heap height: " << minHeap.height() << "\n";

    vector<int> array = {3, 6, 5, 1, 0, 99, 8, 10, 11, 12, 17, 18};
    cout<<endl<<"Now creating a new heap from an array...."<<endl;
    minHeap.buildHeapfromArray(array);

    cout << "Heap after building from an array... "<<endl;
    minHeap.printHeap();
    cout<<endl;
    cout<<"Checking the heap height..."<<endl<<"Heap Height: "<<minHeap.height()<<endl;

    cout<<"Checking the top most element in the heap structure..."<<endl;
    cout<<minHeap.top()<<endl;

    cout<<endl<<"Popping five elements from the heap..."<<endl;
    minHeap.pop();
    minHeap.pop();
    minHeap.pop();
    minHeap.pop();
    minHeap.pop();
    cout<<"After popping two elements from the heap, checking the top most element..."<<endl;
    cout<<minHeap.top()<<endl;

    cout<<"Checking the heap height..."<<endl<<"Heap Height: "<<minHeap.height()<<endl;
    return 0;
}