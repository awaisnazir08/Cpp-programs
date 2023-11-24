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

void countingSort(int arr[], int size, int pos)
{
    int count[10] = {0};
    for (int i = 0; i < size; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    int *result = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        result[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    copy(result, result + size, arr);
    delete[] result;
}

void radixSort(int arr[], int size)
{
    int max = find_max(arr, size);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countingSort(arr, size, pos);
    }

}
int main()
{
    int arr[] = {4, 6, 7, 2, 8, 0, 1,421,4,2,0,9,2,7,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}