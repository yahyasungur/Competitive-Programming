/*
LeetCode 724. Find Pivot Index
Problem Link: https://leetcode.com/problems/find-pivot-index

Author: Yahya Sungur
Date: 10/17/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        size_t size = nums.size();
        if (size == 1)
        {
            return 0;
        }

        vector<int> rightSum(nums);
        
        for (int i = size - 2; i >= 0; i--)
        {
            rightSum[i] += rightSum[i+1];
            nums[size - i - 1] += nums[size - i - 2];
        }

        if (size > 1 && rightSum[1] == 0)
        {
            return 0;
        }
        
        for (size_t i = 1; i < size-1; i++)
        {
            if (nums[i-1] == rightSum[i+1])
            {
                return i;
            }
        }

        if (nums[size-2] == 0)
        {
            return size-1;
        }
        
        return -1;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {2,1,-1};

    int result = solution.pivotIndex(nums);

    cout << result << endl;

    return 0;
}