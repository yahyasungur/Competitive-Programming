/*
LeetCode 1207. Unique Number of Occurrences
Problem Link: https://leetcode.com/problems/unique-number-of-occurrences

Author: Yahya Sungur
Date: 10/30/2024
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> occurenceMap;
        set<int> occurenceCheckSet;

        for (auto &&num : arr)
        {
            occurenceMap[num]++;
        }
        
        for (auto &&element : occurenceMap)
        {
            if (occurenceCheckSet.find(element.second) == occurenceCheckSet.end())
            {
                occurenceCheckSet.insert(element.second);
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1,2,2,1,1,3};

    bool result = solution.uniqueOccurrences(nums);

    cout << result << endl;

    return 0;
}