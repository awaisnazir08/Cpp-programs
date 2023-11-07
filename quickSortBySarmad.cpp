#include <iostream>
using namespace std;
int partition(int a[], int left, int right)
{
    int pivot = a[left];
    
    int lb = left;
    while (left < right)
    {
        while (a[left] <= pivot)
        {
            left++;
        }
        while (a[right] > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swap(a[left], a[right]);
        }
    }
    swap(a[lb], a[right]);
    return right;
}
void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int location = partition(a, left, right);
        quickSort(a, left, location - 1);
        quickSort(a, location + 1, right);
    }
}
int main()
{
    int arr[10] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};

    std::cout << "Original array: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, 10 - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}