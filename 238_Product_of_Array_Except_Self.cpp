/*
LeetCode 238. Product of Array Except Self
Problem Link: https://leetcode.com/problems/product-of-array-except-self

Author: Yahya Sungur
Date: 09/26/2024
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) 
    // {
    //     double sum = 0;
    //     for (auto &num : nums)
    //     {
    //         sum += log2(num);
    //     }

    //     for (size_t i = 0; i < nums.size(); i++)
    //     {
    //         nums[i] = pow(2, sum - ((double)log2(nums[i])));
    //     }

    //     return nums;
    // }

    // vector<int> productExceptSelf(vector<int>& nums) 
    // {
    //     vector<int> prefixArray(nums.size());
    //     prefixArray[0] = nums[0];
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         prefixArray[i] = prefixArray[i-1] * nums[i];
    //     }
        
    //     for (int i = nums.size()-2; i >= 0; i--)
    //     {
    //         nums[i] *= nums[i+1];
    //     }
        
    //     nums[0] = nums[1];
    //     for (int i = 1; i < nums.size()-1; i++)
    //     {
    //         nums[i] = prefixArray[i-1] * nums[i+1];
    //     }
    //     nums[nums.size()-1] = prefixArray[nums.size()-2];

    //     return nums;
    // }

    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> result(nums.size(), 1);

        int value = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            result[i] *= value;
            value *= nums[i];
        }

        value = 1;
        for (int i = nums.size() - 1; i >=0; i--)
        {
            result[i] *= value;
            value *= nums[i];
        }
        
        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 2, 3, 4};

    // {1, 2, 6, 24} --> prefix
    // {24, 24, 12, 4} --> suffix

    // {24, 12, 8, 6} --> result

    vector<int> result = solution.productExceptSelf(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}