#include<iostream>
using namespace std;
bool check_sortness(int arr[], int n)
{
    if(n == 2)
    {
        return (arr[n-1]>= arr[n-2]);
    }
    if(n<2)
    {
        return true;
    }
    if(n > 2 && (arr[n-1]<arr[n-2]))
    {
        return false;
    }
    if(arr[n-1]>= arr[n-2])
    {
        return check_sortness(arr, n-1);
    }
}
int main()
{
    int arr[5] = {1,2,23,4,5};
    cout<<check_sortness(arr,5);
    return 0;
}