/*
LeetCode 1679. Max Number of K-Sum Pairs
Problem Link: https://leetcode.com/problems/max-number-of-k-sum-pairs

Author: Yahya Sungur
Date: 10/02/2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int,int> hashTable;
        int operationNumber = 0;
        int remaining = 0;

        for (auto &&number : nums)
        {
            hashTable[number]++;
        }

        for (auto &&number : hashTable)
        {
            remaining = k - number.first;
            if ((number.second != 0) && (hashTable.find(remaining) != hashTable.end()))
            {
                if (number.first == remaining)
                {
                    operationNumber += number.second/2;
                }
                else
                {
                    operationNumber += min(number.second, hashTable[remaining]);
                }

                hashTable[remaining] = 0;
            }
        }

        return operationNumber;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {3,1,3,4,3};

    int result = solution.maxOperations(nums, 6);

    cout << result << endl;

    return 0;
}