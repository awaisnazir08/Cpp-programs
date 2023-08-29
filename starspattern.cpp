#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for (int j=1;j<=n-i;j++)
        {
            cout<<"  ";
        }
        int k=i;
        while(k>=1)
        {
            cout<<"* ";
            k--;
        }
        for(int a=2;a<=i;a++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=n-i;j>=1;j--)
        {
            cout<<"  ";
        }
        int k=1;
        while(k<=i)
        {
            cout<<"* ";
            k++;
        }
        for(int a=i;a>=2;a--)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}