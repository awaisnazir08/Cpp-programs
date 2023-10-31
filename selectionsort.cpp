#include<iostream>
using namespace std;
void selectionSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[8] = {9,4,2,10,5,8,2,1};
    selectionSort(a,8);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}