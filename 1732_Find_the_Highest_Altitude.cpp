/*
LeetCode 1732. Find the Highest Altitude
Problem Link: https://leetcode.com/problems/find-the-highest-altitude

Author: Yahya Sungur
Date: 10/17/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int max = 0, sum = 0;

        for (auto &&change : gain)
        {
            if ((sum += change) > max)
            {
                max = sum;
            }
        }
        
        return max;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {-4,-3,-2,-1,4,3,2};

    int result = solution.largestAltitude(nums);

    cout << result << endl;

    return 0;
}