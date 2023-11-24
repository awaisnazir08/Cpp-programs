#include<iostream>
using namespace std;
int main(){
    int s = 0;
    int arr[4] = {1,2,3,4};
    for (int i=0;i<4;i++)
    {
        int temp=0;
        for(int j=i;j<4;j++)
        {
            // s+=arr[j];
            temp=j;
            while(temp>=i)
            {
                s+=arr[temp];
                temp--;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}