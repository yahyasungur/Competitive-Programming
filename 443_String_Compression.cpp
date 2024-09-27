/*
LeetCode 443. String Compression
Problem Link: https://leetcode.com/problems/string-compression

Author: Yahya Sungur
Date: 09/27/2024
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) 
    {
        char ch = chars[0];
        int numberOfChars = 1;
        int index = 1;

        for (size_t i = 1; i < chars.size(); i++)
        {
            if (chars[i] == ch)
            {
                numberOfChars++;
            }
            else
            {
                ch = chars[i];

                if (numberOfChars != 1)
                {
                    // Push back the numberOfChars
                    string numberOfCharsString = to_string(numberOfChars);
                    for (auto &&character : numberOfCharsString)
                    {
                        chars[index] = character;
                        index++;
                    }
                }

                // Update numberOfChars
                numberOfChars = 1;

                // Push back the new ch
                chars[index] = ch;
                index++;
            }
        }

        if (numberOfChars != 1)
        {
            // Push back the numberOfChars
            string numberOfCharsString = to_string(numberOfChars);
            for (auto &&character : numberOfCharsString)
            {
                chars[index] = character;
                index++;
            }
        }
        
        chars.erase(chars.begin()+index, chars.end());
        return chars.size();
    }
};

int main()
{
    Solution solution;
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    int result = solution.compress(chars);

    cout << result << endl;

    for (auto &&ch : chars)
    {
        cout << ch << ",";
    }
    cout << endl;

    return 0;
}