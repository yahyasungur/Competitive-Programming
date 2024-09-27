/*
LeetCode 334. Increasing Triplet Subsequence
Problem Link: https://leetcode.com/problems/increasing-triplet-subsequence

Author: Yahya Sungur
Date: 09/27/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int first =INT_MAX, second = INT_MAX, third = INT_MAX;

        for (auto &&num : nums)
        {
            if (num < first)
            {
                first = num;
            }
            else if (num < second && num != first)
            {
                second = num;
            }
            else if (num < third && num != first && num != second)
            {
                third = num;
                if (first   !=  INT_MAX &&
                    second  !=  INT_MAX && 
                    first   <   second  && 
                    second  <   third   )
                {
                    return true;
                }
            }
            else if (num == INT_MAX)
            {
                third = INT_MAX-1;
                if (first   !=  INT_MAX &&
                    second  !=  INT_MAX && 
                    first   <   second  && 
                    second  <   third   )
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4,5,2147483647,1,2};

    bool result = solution.increasingTriplet(nums);

    cout << result << endl;

    return 0;
}