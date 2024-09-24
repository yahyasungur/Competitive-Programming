/*
LeetCode 345. Reverse Vowels of a String
Problem Link: https://leetcode.com/problems/reverse-vowels-of-a-string

Author: Yahya Sungur
Date: 09/24/2024
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) 
    {
        int begin = 0;
        int end = s.size()-1;

        while (true)
        {
            while (true)
            {
                if (
                    s[begin] == 97  || s[begin] == 65 ||
                    s[begin] == 101 || s[begin] == 69 ||
                    s[begin] == 105 || s[begin] == 73 ||
                    s[begin] == 111 || s[begin] == 79 ||
                    s[begin] == 117 || s[begin] == 85
                    )
                {
                    break;
                }

                begin++;
                
                if (begin >= s.size())
                {
                    return s;
                }
            }

            while (true)
            {
                if (
                    s[end] == 97  || s[end] == 65 ||
                    s[end] == 101 || s[end] == 69 ||
                    s[end] == 105 || s[end] == 73 ||
                    s[end] == 111 || s[end] == 79 ||
                    s[end] == 117 || s[end] == 85
                    )
                {
                    break;
                }

                end--;

                if (end < 0)
                {
                    return s;
                }
            }
            
            if (begin >= end)
            {
                break;
            }
            else
            {
                if (s[begin] != s[end])
                {
                    char temp = s[begin];
                    s[begin] = s[end];
                    s[end] = temp;
                }

                begin++;
                end--;
            }
        }

        return s;
    }
};

int main()
{
    Solution solution;

    string result = solution.reverseVowels("IceCreAm");

    cout << result << endl;

    return 0;
}