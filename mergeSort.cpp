#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &a, int left, int middle, int right)
    {
        int n1 = middle - left + 1;
        int n2 = right - middle;
        vector<int> a1(n1);
        vector<int> a2(n2);
        for (int i = 0; i < n1; i++)
        {
            a1[i] = a[left + i];
        }
        for (int i = 0; i < n2; i++)
        {
            a2[i] = a[middle + i+1];  //why plus 1
        }
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
    }
    void mergeSort(vector<int> &a, int left, int right)
    {
        if (left < right)
        {
            int middle = (left + right) / 2;
            mergeSort(a, left, middle);
            mergeSort(a, middle + 1, right);
            merge(a, left, middle, right);
        }
    }

    // vector<int> sortArray(vector<int> &nums)
    // {
    //     mergeSort(nums, 0, nums.size() - 1);
    //     return nums;
    // }
};
int main()
{
    Solution s;
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    s.mergeSort(arr, 0,arr_size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}