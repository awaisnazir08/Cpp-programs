//limitation: array must be sorted in ascending or descending order..!!
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int left, int right, int key)
{
    if (left <= right)
    {
        int m = (left + right) / 2;
        if (key == arr[m])
        {
            return m;
        }
        else if (key > arr[m])
        {
            return binarySearch( arr, m+1, right, key);
        }
        else{
            return binarySearch(arr,left,m-1,key);
        }
    }
    return -1;
}
int main()
{
    int n;
    cout << "enter size: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "enter key: ";
    int key;
    cin >> key;
    cout << binarySearch(arr, 0, n, key)+1;
    return 0;
}