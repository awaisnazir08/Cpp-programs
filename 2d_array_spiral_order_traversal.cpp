#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int arr[5][6] = {{1, 5, 7, 9, 10, 11},
                     {6, 10, 12, 20, 21, 13},
                     {12, 3, 23, 15, 3, 9},
                     {7, 23, 17, 32, 94, 30},
                     {5, 2, 1, 7, 8, 4}};

    int row_start = 0;
    int row_end = 4;
    int column_start = 0;
    int column_end = 5;
    while (row_start <= row_end && column_start <= column_end)
    {
        if (column_start <= column_end && row_start <= row_end)
        {
            for (int j = column_start; j <= column_end; j++)
            {
                cout << arr[row_start][j] << " ";
            }
            row_start++;
        }

        if (row_start <= row_end  && column_start <= column_end)
        {
            for (int i = row_start; i <= row_end; i++)
            {
                cout << arr[i][column_end] << " ";
            }
            column_end--;
        }

        if (column_start <= column_end & row_start <= row_end)
        {
            for (int j = column_end; j >= column_start; j--)
            {
                cout << arr[row_end][j] << " ";
            }
            row_end--;
        }

        if (row_end >= row_start  && column_start <= column_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                cout << arr[i][column_start] << " ";
            }
            column_start++;
        }

    }
    return 0;
}