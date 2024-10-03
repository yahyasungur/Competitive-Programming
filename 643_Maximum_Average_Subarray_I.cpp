/*
LeetCode 643. Maximum Average Subarray I
Problem Link: https://leetcode.com/problems/maximum-average-subarray-i

Author: Yahya Sungur
Date: 10/03/2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int grandTotal, subTotal = 0;

        for (size_t i = 0; i < k; i++)
        {
            subTotal += nums[i];
        }
        
        grandTotal = subTotal;

        for (size_t i = k; i < nums.size(); i++)
        {
            subTotal += nums[i] - nums[i-k];
            if (subTotal > grandTotal)
            {
                grandTotal = subTotal;
            }
        }

        return (double)grandTotal/(double)k;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1,12,-5,-6,50,3};

    double result = solution.findMaxAverage(nums, 4);

    cout << result << endl;

    return 0;
}