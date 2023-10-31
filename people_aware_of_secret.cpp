#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> people;
        people.push_back(0);
        for (int i = 0; i < n; i++)
        {
            for (size_t j = 0; j < people.size(); j++)
            {
                people[j] += 1;
            }
            people.erase(std::remove_if(people.begin(), people.end(), [forget](int element)
                                        {
            // Condition: Remove elements greater than 3
            return element > forget; }),
                         people.end());
            for (size_t j = 0; j < people.size(); j++)
            {
                if (people[j] > delay && people[j] <= forget)
                {
                    people.push_back(1);
                }
            }
        }
        return people.size() % (1000000007);
    }
};
int main()
{

    return 0;
}