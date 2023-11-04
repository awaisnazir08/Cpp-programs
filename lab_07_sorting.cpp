#include<iostream>
#include <ctime>
#include <chrono>  //using standard library chrono for calculating time in milliseconds
#include <cstdlib>
using namespace std;
class Timer  //class to calculate the time of the functions
{
private:
    chrono::time_point<chrono::high_resolution_clock> start_time; // variable to store the starting time
    chrono::time_point<chrono::high_resolution_clock> end_time;  // variable to stor the ending time
public:
    Timer()  //constructor that starts the timer as soon as the object of Timer class is created
    {
        start_time = chrono::high_resolution_clock::now();
    }
    void time_end() // function which stores the time when the function implementation has completed
    {
        end_time = chrono::high_resolution_clock::now();
    }
    void calculate_time()  //function to calculate the time taken for the function to run based on the difference of the starting and the ending time
    {
        time_end();
        chrono::duration<double, milli> duration = end_time - start_time;
        cout << "Duration: " << duration.count() << " milliseconds" << endl;  //prints the time taken to run the function
    }

};
class SortingAlgorithms
{
private:
    // Merge function for merge sort
    void merge(int a[], int left, int middle, int right)
    {
        // Calculate the sizes of the two subarrays
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays to hold the subarrays
        int* a1 = new int[n1];
        int* a2 = new int[n2];

        // Copy data to the temporary arrays
        for (int i = 0; i < n1; i++)
        {
            a1[i] = a[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            a2[i] = a[middle + i + 1];
        }

        // Merge the two subarrays back into the original array
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (a1[i] < a2[j])
            {
                a[k] = a1[i];
                i++;
            }
            else
            {
                a[k] = a2[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements from the temporary arrays
        while (i < n1)
        {
            a[k] = a1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            a[k] = a2[j];
            j++;
            k++;
        }

        // Clean up the temporary arrays
        delete[] a1;
        delete[] a2;
    }

public:
    // Selection sort algorithm
    void selectionSort(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int min = i;
            for (int j = i; j < n; j++)
            {
                if (a[min] > a[j])
                {
                    min = j;
                }
            }
            // Swap the minimum element with the current element
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    // Merge sort algorithm
    void mergeSort(int a[], int left, int right)
    {
        if (left < right)
        {
            int middle = (left + right) / 2;
            // Recursively sort the left and right halves of the array
            mergeSort(a, left, middle);
            mergeSort(a, middle + 1, right);
            // Merge the sorted halves back together
            merge(a, left, middle, right);
        }
    }

    // Insertion sort algorithm
    void insertionSort(int a[], int n)
    {
        if (n == 1)
        {
            return;
        }
        for (int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;
            // Move elements greater than the key to one position ahead of their current position
            while (j >= 0 && key < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            // Place the key in its correct position
            a[j + 1] = key;
        }
    }

    // Bubble sort algorithm
    void bubbleSort(int arr[], int size) {
        // Base case: if the array has only one element, it is already sorted
        if (size == 1) {
            return;
        }

        // Iterate through the array and swap adjacent elements if they are out of order
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        // Recursively sort the remaining elements
        bubbleSort(arr, size - 1);
    }
};



int main()
{
    srand(time(0)); // Seed the random number generator with the current time

    // Sizes of the arrays to be generated
    int sizes[] = { 100, 1000, 10000 };

    SortingAlgorithms sorter;

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++)
    {
        int size = sizes[i];
        int* arr = new int[size];

        // Generate a random array of size 'size' with values in the range [1, 100]
        for (int j = 0; j < size; j++)
        {
            arr[j] = 1 + rand() % 100;
        }

        // Copy the array for each sorting algorithm to ensure they work on the same data
        int* arrBubble = new int[size];
        int* arrSelection = new int[size];
        int* arrInsertion = new int[size];
        int* arrMerge = new int[size];
        copy(arr, arr + size, arrBubble);
        copy(arr, arr + size, arrSelection);
        copy(arr, arr + size, arrInsertion);
        copy(arr, arr + size, arrMerge);

        cout << "\t\t\t\t\tArray Size: " << size << endl;

        // Bubble Sort
        cout << "Bubble Sort" << endl;
        Timer* t1 = new Timer();
        sorter.bubbleSort(arrBubble, size);
        t1->calculate_time();
        cout << endl;

        // Selection Sort
        cout << "Selection Sort" << endl;
        Timer* t2 = new Timer();
        sorter.selectionSort(arrSelection, size);
        t2->calculate_time();
        cout << endl;

        // Insertion Sort
        cout << "Insertion Sort" << endl;
        Timer* t3 = new Timer();
        sorter.insertionSort(arrInsertion, size);
        t3->calculate_time();
        cout << endl;


        // Merge Sort
        cout << "Merge Sort" << endl;
        Timer* t4 = new Timer();
        sorter.mergeSort(arrMerge, 0, size - 1);
        t4->calculate_time();
        cout << endl;

        cout << "<-------------------------------------------------------------------------------------------------->" << endl;


        //// Output the results
        //std::cout << "Array size: " << size << " elements\n";
        //std::cout << "Bubble Sort Time: " << bubbleSortTime << " seconds\n";
        //std::cout << "Selection Sort Time: " << selectionSortTime << " seconds\n";
        //std::cout << "Insertion Sort Time: " << insertionSortTime << " seconds\n";
        //std::cout << "Merge Sort Time: " << mergeSortTime << " seconds\n\n";

        // Clean up dynamically allocated memory
        delete[] arr;
        delete[] arrBubble;
        delete[] arrSelection;
        delete[] arrInsertion;
        delete[] arrMerge;
        delete t1, t2, t3, t4;
    }

    return 0;
}