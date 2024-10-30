/*
LeetCode 2215. Find the Difference of Two Arrays
Problem Link: https://leetcode.com/problems/find-the-difference-of-two-arrays

Author: Yahya Sungur
Date: 10/30/2024
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> numset1(nums1.begin(), nums1.end());
        set<int> numset2(nums2.begin(), nums2.end());

        vector<vector<int>> result;
        vector<int> array;

        for (auto &&num : numset1)
        {
            if (numset2.find(num) == numset2.end())
            {
                array.push_back(num);
            }
        }
        
        result.push_back(array);
        array.clear();

        for (auto &&num : numset2)
        {
            if (numset1.find(num) == numset1.end())
            {
                array.push_back(num);
            }
        }

        result.push_back(array);

        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};

    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    for (auto &&vec : result)
    {
        for (auto &&num : vec)
        {
            cout << num << ",";
        }
        cout << endl;
    }

    return 0;
}