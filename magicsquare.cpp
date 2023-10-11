#include <iostream>
using namespace std;
#include <math.h>
#include<stack>
void creatingMagic()
{
    stack<int> s;
    int n;
    cout << "Enter the size of the magic square: ";
    cin >> n;
    int **d2_arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        d2_arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d2_arr[i][j] = 0;
        }
    }
    int last = n * n;
    int row = 0;
    int col = (n / 2);
    for (int i = 1; i <= last; i++)
    {
        if(row < 0)
        {
            row = n - 1;
        }
        if(col >= n)
        {
            col = 0;
        }
        if(d2_arr[row][col] != 0)
        {
            int r = s.top();
            s.pop();
            int c = s.top();
            s.pop();
            r++;
            d2_arr[r][c] = i;
            row = r;
            col = c;
            s.push(col);
            s.push(row);
        }
        else
        {
            d2_arr[row][col]= i;
            s.push(col);
            s.push(row);
        }
        row --;
        col++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << d2_arr[i][j] << "  ";
        }
        cout << endl;
    }

    delete[] d2_arr;
    d2_arr = NULL;
}
int main()
{
    creatingMagic();
    return 0;
}