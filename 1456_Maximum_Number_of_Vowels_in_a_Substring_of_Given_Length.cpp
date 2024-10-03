/*
LeetCode 1456. Maximum Number of Vowels in a Substring of Given Length
Problem Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

Author: Yahya Sungur
Date: 10/03/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) 
    {
        // ASCII values
        /*
        a : 97 , e : 101 , i : 105 , o : 111 , u : 117
        */

        int numberOfVowels = 0;
        int maxNumberOfVovels;

        for (size_t i = 0; i < k; i++)
        {
            if (s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117)
            {
                numberOfVowels++;
            }
        }
        
        maxNumberOfVovels = numberOfVowels;

        for (size_t i = k; i < s.size(); i++)
        {
            if (maxNumberOfVovels >= k)
            {
                return k;
            }
            
            if (s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117)
            {
                numberOfVowels++;
            }
            
            if (s[i-k] == 97 || s[i-k] == 101 || s[i-k] == 105 || s[i-k] == 111 || s[i-k] == 117)
            {
                numberOfVowels--;
            }
            
            if (numberOfVowels > maxNumberOfVovels)
            {
                maxNumberOfVovels = numberOfVowels;
            }
        }

        return maxNumberOfVovels;
    }
};

int main()
{
    Solution solution;

    int result = solution.maxVowels("abciiidef", 3);

    cout << result << endl;

    return 0;
}