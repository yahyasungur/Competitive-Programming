/*
LeetCode 2390. Removing Stars From a String
Problem Link: https://leetcode.com/problems/removing-stars-from-a-string

Author: Yahya Sungur
Date: 10/31/2024
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) 
    {
        int numberOfStar = 0;
        string result;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                numberOfStar++;
            }
            else if (numberOfStar > 0)
            {
                numberOfStar--;
            }
            else
            {
                result.push_back(s[i]);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    Solution solution;

    string result = solution.removeStars("leet**cod*e");

    cout << result << endl;

    return 0;
}