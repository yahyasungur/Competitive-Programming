/*
LeetCode 11. Container With Most Water
Problem Link: https://leetcode.com/problems/container-with-most-water

Author: Yahya Sungur
Date: 10/02/2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int leftIndex = 0, rightIndex = height.size() -1;
        int area = 0;
        int tempArea = 0;

        while (true)
        {
            tempArea = (rightIndex-leftIndex)*min(height[rightIndex], height[leftIndex]);
            if (tempArea > area)
            {
                area = tempArea;
            }

            if (height[leftIndex] < height[rightIndex])
            {
                leftIndex++;
            }
            else
            {
                rightIndex--;
            }

            if (leftIndex >= rightIndex)
            {
                break;
            }
        }

        return area;
    }
};

int main()
{
    Solution solution;

    vector<int> heights = {1,8,6,2,5,4,8,3,7};

    int result = solution.maxArea(heights);

    cout << result << endl;

    return 0;
}