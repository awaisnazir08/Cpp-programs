#include <iostream>
using namespace std;

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
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[8] = {9, 4, 2, 10, 5, 8, 2, 1};
    insertionSort(a, 8);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}