/*
LeetCode 1431. Kids With the Greatest Number of Candies
Problem Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

Author: Yahya Sungur
Date: 09/24/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int greatest = candies[0];

        // Find the greatest number of candies in vector
        for (size_t i = 1; i < candies.size(); i++)
        {
            if (candies[i] > greatest)
            {
                greatest = candies[i];
            }
        }
        
        vector<bool> result;
        for (size_t i = 0; i < candies.size(); i++)
        {
            result.push_back(((candies[i] + extraCandies) >= greatest));
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;

    vector<bool> result = solution.kidsWithCandies(candies, extraCandies);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }
    cout << endl;

    return 0;
}