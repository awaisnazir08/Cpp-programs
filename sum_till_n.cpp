#include<iostream>
using namespace std;
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    
    return n + sum(n-1);
}

int sum_arr(int arr[], int n)
{
    if(n==1)
    {
        return arr[0];
    }
    return arr[n-1] + sum_arr(arr, n-1);
}
int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<sum_arr(array,10)<<endl;
    cout<<sum(5);
    return 0;
}