#include <iostream>
#include <vector>
using namespace std;

int find_max(vector<int> &a)
{
    int max = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int main()
{
    vector<int> a = {5, 1, 2, 4, 2, 7, 5, 2, 9, 7};
    int max = find_max(a);
    vector<int> f(max + 1, 0);
    vector<int> com_f(max + 1);
    for (int i = 0; i <= f.size(); i++)
    {
        f[a[i]]++;
    }
    com_f = f;

    for (int i = 1; i <= com_f.size(); i++)
    {
        com_f[i] += com_f[i - 1];
    }

    vector<int> result(a.size());
    for (int i = result.size()-1; i >= 0; i--)
    {
        result[--com_f[a[i]]] = a[i];
        // --com_f[a[i]];
    }

    for (int i = 0; i < f.size(); i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < com_f.size(); i++)
    {
        cout << com_f[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}