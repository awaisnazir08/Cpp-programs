#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())
        {
            return 0;
        }
        else if(cost.size()==1)
        {
            return cost[0];
        }
    int check = -1;
        int i = 0;
        // if(cost[1]>=cost[0] && (1+2)>=cost.size())
        // {
        //     i = 1;
        // }
        int pay = 0;
        int pay2 = 0;
        while(i < cost.size())
        {
            if((i+1) == cost.size() || (i+2) == cost.size())
            {
                if(check >= 0)
                {
                    break;
                }
                pay+=cost[i];
                break;
            }
            if(cost[i+1] < cost[i+2] && (i + 4)>=cost.size())
            {
                check ++;
                int p1 = pay + cost[i];
                i +=1;
                int j = i + 1;
                int p2 = pay + cost[i-1];
                if((j+1) == cost.size() || (j+2) == cost.size())
                {
                    
                    p1+=cost[i];
                    p2 += cost[j];
                    if(p1<p2)
                    {
                        pay = p1;
                    }
                    else
                    {
                        pay = p2;
                    }
                }
            }
            else if(cost[i+1] < cost[i + 2])
            {
                pay += cost[i];
                i +=1 ;
            }
            else
            {
                pay += cost[i];
                i+=2;
            }
        }
        i = 1;
        while(i < cost.size())
        {
            if((i+1) == cost.size() || (i+2) == cost.size())
            {
                pay2+=cost[i];
                break;
            }
            if(cost[i+1] < cost[i + 2])
            {
                pay2 += cost[i];
                i +=1 ;
            }
            else
            {
                pay2 += cost[i];
                i+=2;
            }
        }
        if(pay>pay2)
        {
            return pay2;
        }
        return pay;

    }
};


int main()
{
    Solution s;
    vector<int> a = {0,1,2,2};
    cout<< s.minCostClimbingStairs(a);
}