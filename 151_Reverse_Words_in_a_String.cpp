/*
LeetCode 151. Reverse Words in a String
Problem Link: https://leetcode.com/problems/reverse-words-in-a-string

Author: Yahya Sungur
Date: 09/24/2024
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) 
    {
        // Remove leading spaces if any
        while (s[0] == ' ')
        {
            s.erase(s.begin());
        }

        if (s.size() == 0)
        {
            return s;
        }

        // Remove trailing spaces if any
        while (s[s.size()-1] == ' ')
        {
            s.erase(s.begin() + s.size() - 1);
        }
        
        if (s.size() == 0)
        {
            return s;
        }

        // Remove unnecessary spaces
        int index = 0;
        while (index < s.size())
        {
            if ((index + 1 >= s.size()) && (s[index] == ' ') && (s[index+1] == ' '))
            {
                s.erase(s.begin() + index);
            }

            index++;
        }
        
        vector<string> strings;
        string str = "";
        s += " ";
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                str.push_back(s[i]);
            }
            else if (str != "")
            {
                strings.push_back(str);
                str.clear();
            }
        }
        
        s.clear();

        for (int i = strings.size()-1; i >= 0; i--)
        {
            s += " " + strings[i];
        }

        s.erase(s.begin());

        return s;
    }
};

int main()
{
    Solution solution;

    string result = solution.reverseWords("the sky is blue");

    cout << result << endl;

    return 0;
}