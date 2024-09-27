/*
LeetCode 283. Move Zeroes
Problem Link: https://leetcode.com/problems/move-zeroes

Author: Yahya Sungur
Date: 09/27/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int zeroIndex = 0, nonZeroIndex = 0, size = nums.size();

        while (true)
        {
            // Find first zero
            while (zeroIndex < size)
            {
                if (nums[zeroIndex] == 0)
                {
                    break;
                }
                zeroIndex++;
            }
            
            // Find first nonzero
            while (nonZeroIndex < size)
            {
                if (nums[nonZeroIndex] != 0)
                {
                    break;
                }
                nonZeroIndex++;
            }
            
            if (zeroIndex >= size || nonZeroIndex >= size)
            {
                return;
            }

            if (nonZeroIndex <= zeroIndex)
            {
                nonZeroIndex = zeroIndex+1;
                continue;
            }

            // Swap zero and nonzero
            nums[zeroIndex] = nums[nonZeroIndex];
            nums[nonZeroIndex] = 0;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {0};

    solution.moveZeroes(nums);

    for (auto &&num : nums)
    {
        cout << num << ",";
    }
    cout << endl;

    return 0;
}