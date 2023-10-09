#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> using_n_square_time_complexity(vector<int> v)
{
    // vector<int> v = {1, 4, -4, 0, 6, 9, 2, 8, 2};
    vector<int> f;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[i])
            {
                f.push_back(v[j]);
                break;
            }
            else if (((j + 1) >= v.size()) && (v[j] >= v[i]))
            {
                f.push_back(-1);
                break;
            }
        }
    }
    f.push_back(-1);
    return f;
}
vector<int> using_n_time_complexity(vector<int> v)
{
    stack<int> s;
    vector<int> result;
    s.push(-1);
        // vector<int> v = {1, 4, 7, 0, 6, 9, 2, 8, 2};
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (s.top() >= v[i])
        {
            s.pop();
        }
        result.push_back(s.top());
        s.push(v[i]);
    }
    return result;
}
int main()
{
    vector<int> v = {1, 4, 7, 0, 6, 9, 2, 8, 2};
    vector<int> result;
    // f = using_n_square_time_complexity(v);

    // for (int i = 0; i < f.size(); i++)
    // {
    //     cout << f[i] << " ";
    // }

    result = using_n_time_complexity(v);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}