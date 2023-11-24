#include <iostream>
#include <algorithm>
using namespace std;
int find_max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size) {
    // Find the maximum element in the array
    int maxElement = find_max(arr, size);

    // Create a frequency array to store the frequency of each element
    int* frequency = new int[maxElement + 1]();

    // calculating frequencies
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Update the frequency array to store the cumulative frequency
    for (int i = 1; i <= maxElement; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Create a temporary array to store the sorted result
    int* result = new int[size];

    // Build the sorted array using the frequency array
    for (int i = size - 1; i >= 0; i--) {
        result[--frequency[arr[i]]] = arr[i];
        // frequency[arr[i]]--;
    }

    // Copy the sorted result back to the original array
    copy(result, result + size, arr);

    // Free dynamically allocated memory
    delete[] frequency;
    delete[] result;
}

int main() {
    int arr[] = {4,6,7,2,2,0,1,56355350, 7, 1, 5, 3, 8, 6,985337};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
