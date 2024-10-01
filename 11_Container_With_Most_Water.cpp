/*
LeetCode 11. Container With Most Water
Problem Link: https://leetcode.com/problems/container-with-most-water

Author: Yahya Sungur
Date: 10/01/2024
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
        int area = (rightIndex-leftIndex)*min(height[rightIndex], height[leftIndex]);
        int tempArea = 0;

        for (size_t i = 1; i < height.size(); i++)
        {
            // if (i > rightIndex || (height.size()-1-i) < leftIndex)
            // {
            //     break;
            // }

            if (height[i] > height[leftIndex])
            {
                tempArea = (rightIndex-i)*min(height[rightIndex], height[i]);
                if (tempArea >= area)
                {
                    leftIndex = i;
                    area = tempArea;
                }
            }
            
            if (height[height.size()-1-i] > height[rightIndex])
            {
                tempArea = ((height.size()-1-i)-leftIndex)*min(height[height.size()-1-i], height[leftIndex]);
                if (tempArea >= area)
                {
                    rightIndex = height.size()-1-i;
                    area = tempArea;
                }
            }
        }

        return area;
    }
};

int main()
{
    Solution solution;

    vector<int> heights = {2,3,4,5,18,17,6};

    int result = solution.maxArea(heights);

    cout << result << endl;

    return 0;
}