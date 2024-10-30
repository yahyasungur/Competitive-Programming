/*
LeetCode 1657. Determine if Two Strings Are Close
Problem Link: https://leetcode.com/problems/determine-if-two-strings-are-close

Author: Yahya Sungur
Date: 10/30/2024
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if (word1.size() != word2.size())
        {
            return false;
        }
        
        unordered_set<char> word1CharSet(word1.begin(), word1.end());
        unordered_set<char> word2CharSet(word2.begin(), word2.end());

        if (word1CharSet != word2CharSet)
        {
            return false;
        }

        unordered_map<char,int> word1Map;
        unordered_map<char,int> word2Map;

        for (auto &&character : word1)
        {
            word1Map[character]++;
        }

        for (auto &&character : word2)
        {
            word2Map[character]++;
        }

        if (word1Map.size() != word2Map.size())
        {
            return false;
        }

        vector<int> word1Pattern;
        vector<int> word2Pattern;

        for (auto &&elem : word1Map)
        {
            word1Pattern.push_back(elem.second);
        }
        
        for (auto &&elem : word2Map)
        {
            word2Pattern.push_back(elem.second);
        }
        
        sort(word1Pattern.begin(), word1Pattern.end());
        sort(word2Pattern.begin(), word2Pattern.end());

        for (size_t i = 0; i < word1Pattern.size(); i++)
        {
            if (word1Pattern[i] != word2Pattern[i])
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

    string word1 = "aaabbbbccddeeeeefffff", word2 = "aaaaabbcccdddeeeeffff";

    bool result = solution.closeStrings(word1, word2);

    cout << result << endl;

    return 0;
}