#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int> arr, int n, int key)
{
    for(int i=0; i<arr.size(); i++)
    {
        if (key==arr[i])
        {
            return i+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"enter size: ";
    cin>>n;
    vector<int> arr(n);
    for (int i=0; i<arr.size(); i++)
    {
        cin>>arr[i];
    }
    cout<<"enter key: ";
    int key;
    cin>>key;
    cout<<linearSearch(arr, n, key);
    return 0;
}