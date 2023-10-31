#include<iostream>
using namespace std;
bool isPowerOfTwo(int n) {
        int static sum = 1;
        if(sum==n)
        {
            return true;
        }
        else if(sum>n)
        {
            return false;
        }
        else
        {
            sum = 2*sum;
            return  isPowerOfTwo(n);
        }
    }
int main()
{
    cout<<isPowerOfTwo(4);
    return 0;
}