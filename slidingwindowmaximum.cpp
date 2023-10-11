#include<iostream>
using namespace std;
#include<vector>
#include<deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
       vector<int> max_values;
       int mx = INT_MIN;
       for(int i = 0; i < k; i ++)
       {
           dq.push_back(nums[i]);
       }
       for (auto it = dq.begin(); it != dq.end(); ++it) 
       {
            if(*it > mx)
            {
                mx = *it;
            }
       }
        max_values.push_back(mx);
        for(int i = k; i < nums.size(); i++)
        {
            dq.pop_front();
            dq.push_back(nums[i]);
            mx = INT_MIN;
        for (auto it = dq.begin(); it != dq.end(); ++it) 
        {
            if(*it > mx)
            {
                mx = *it;
            }
        }
        max_values.push_back(mx);
    }
    return max_values;

    }
};



class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
       std::deque<int> dq;
       std::vector<int> max_values;
       
       for (int i = 0; i < k; i++) {
           while (!dq.empty() && nums[i] >= nums[dq.back()])
               dq.pop_back();
           dq.push_back(i);
       }
       
       for (int i = k; i < nums.size(); i++) {
           max_values.push_back(nums[dq.front()]);
           
           // Remove elements outside the window
           while (!dq.empty() && dq.front() <= i - k)
               dq.pop_front();
           
           // Remove elements that are smaller than the current element
           while (!dq.empty() && nums[i] >= nums[dq.back()])
               dq.pop_back();
           
           dq.push_back(i);
       }
       
       max_values.push_back(nums[dq.front()]);  // Add the maximum for the last window
       
       return max_values;
    }
};