/*
LeetCode 1768. Merge Strings Alternately
Problem Link: https://leetcode.com/problems/merge-strings-alternately

Author: Yahya Sungur
Date: 09/23/2024
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string mergeAlternately(string word1, string word2) {
    int sizeOfLongerString = max(word1.size(), word2.size());
    string result = "";

    for (size_t i = 0; i < sizeOfLongerString; i++)
    {
        if (i < word1.size())
        {
            result += word1[i];
        }

        if (i < word2.size())
        {
            result += word2[i];
        }
    }
    
    return result;
}

int main()
{
    string result = mergeAlternately("abcd", "pq");
    cout << result << endl;
    return 0;
}