/*
LeetCode 1493. Longest Subarray of 1's After Deleting One Element
Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

Author: Yahya Sungur
Date: 10/15/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxDistance = 0;
        vector<int> indexOfZeros;
        indexOfZeros.push_back(-1);

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
            {
                indexOfZeros.push_back(i);
            }
        }
        
        indexOfZeros.push_back(nums.size());

        if (indexOfZeros.size() == 2)
        {
            return nums.size() - 1;
        }
        
        for (size_t i = 2; i < indexOfZeros.size(); i++)
        {
            if ((indexOfZeros[i] - indexOfZeros[i-2]) > maxDistance)
            {
                maxDistance = indexOfZeros[i] - indexOfZeros[i-2];

            }
        }

        return maxDistance - 2;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1,1,0,0,1,1,1,0,1};

    int result = solution.longestSubarray(nums);

    cout << result << endl;

    return 0;
}