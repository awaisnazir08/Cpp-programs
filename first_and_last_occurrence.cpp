#include<iostream>
using namespace std;
void display_occurrence(int arr[], int n, int num)
{
    static int i = -2;
    if(n==0)
    {
        if(i != -1)
        {
            cout<<i<<endl;
        }
        return;
    }
    if(arr[n-1] == num &&(i == -2))
    {
        cout<< n-1<<endl;
        i = -1;
    }
    else if(arr[n-1] == num)
    {
        i = n-1;
    }
    return display_occurrence(arr,n-1, num);
}
int main()
{
    int arr[10] ={1,3,2,5,3,2,3,7,3,19};
    display_occurrence(arr, 10, 2);
    return 0;
}