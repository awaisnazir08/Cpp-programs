#include<iostream>
using namespace std;
void display(int n)
{
    if(n<=0)
    {
        return;
    }
    // cout<<(n);
    display(n-1);
    cout<<n;
    
}
int main()
{
    display(8);
    return 0;
}