/*
LeetCode 392. Is Subsequence
Problem Link: https://leetcode.com/problems/is-subsequence

Author: Yahya Sungur
Date: 10/01/2024
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if (s.size() == 0)
        {
            return true;
        }

        int indexOfSource = 0;
        for (auto &&character : t)
        {
            if (s[indexOfSource] == character)
            {
                indexOfSource++;
                if (indexOfSource >= s.size())
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main()
{
    Solution solution;
    bool result = solution.isSubsequence("axc","ahbgdc");

    cout << result << endl;

    return 0;
}