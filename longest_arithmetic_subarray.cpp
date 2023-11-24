#include<iostream>
using namespace std;
int max(int a, int b)
{
    if(a>b){
        return a;
    }
    return b;
}
int main()
{
    int arr[10] = {2,4,6, 7, 10, 13, 16, 19, 22, 30};
    int diff = arr[1]-arr[0];
    int curr = 2;
    int temp = 0;
    int m = 0;
    for (int i=1; i<9 ;i++)
    {
        
        if(arr[i+1]-arr[i]==diff)
        {
            curr+=1;
            m=max(temp,curr);
        }
        else{
            temp = curr;
            diff = arr[i+1]-arr[i];
            curr = 2;
            m = max(temp, curr);
        }
    }
    cout<<m<<endl;
    return 0;
}