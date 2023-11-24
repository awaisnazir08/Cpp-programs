#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find_max(string arr[], int size)
{
    int max_len = arr[0].length();
    for (int i = 0; i < size; i++)
    {
        if (arr[i].length() > max_len)
        {
            max_len = arr[i].length();
        }
    }
    return max_len;
}

// void countingSort(string arr[], int size, int pos)
// {
//     const int RANGE = 26;
//     vector<int> count(RANGE + 1, 0);
//     string *result = new string[size];

//     for (int i = 0; i < size; i++)
//     {
//         if(arr[i].length()<= pos + 1)
//         {
//             count[RANGE]++;
//         }
//         else{
//             count[arr[i][pos]-97]++;
//         }
//     }

//     for (int i = 1; i <= RANGE; i++)
//     {
//         count[i] += count[i - 1];
//     }

//     for (int i = size - 1; i >= 0; i--)
//     {
//         if(arr[i].length()<=pos + 1)
//         {
//             result[--count[RANGE]] = arr[i];
//         }
//         else{
//         result[--count[arr[i][pos]-97]] =  arr[i];
//         }
//     }

//     copy(result, result + size, arr);
//     delete[] result;
// }

void countingSort(string arr[], int size, int pos)
{
    const int RANGE = 26;
    vector<int> count(RANGE + 1, 0);
    string *result = new string[size];

    for (int i = 0; i < size; i++)
    {
        if (arr[i].length() <= pos)
        {
            count[0]++;
        }
        else
        {
            count[arr[i][pos] - 'a']++;
        }
    }

    for (int i = 1; i <= RANGE; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i].length() <= pos)
        {
            result[--count[0]] = arr[i];
        }
        else
        {
            result[--count[arr[i][pos] - 'a']] = arr[i];
        }
    }

    copy(result, result + size, arr);
    delete[] result;
}

void radixSort(string arr[], int size)
{
    int max_len = find_max(arr, size);
    for (int pos = 0; pos < max_len; pos++)
    {
        countingSort(arr, size, pos);
    }
}

int main()
{
    string arr[] = {"aadsy","bali","aas"};
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
