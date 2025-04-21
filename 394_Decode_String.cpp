/*
LeetCode 394. Decode String
Author: Yahya Sungur
Date: 04/21/2025
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        string decodeString(string s) 
        {
            string result = "";
            string timeString = "";
            int times = 1;

            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    timeString += s[i];
                }
                else if (s[i] == '[')
                {
                    times = stoi(timeString.c_str());
                    string tempString = "";
                    int count = 0;
                    i++;
                    
                    while (i < s.size())
                    {
                        if (s[i] == '[')
                        {
                            count++;
                            tempString += s[i];
                        }
                        else if (s[i] == ']')
                        {
                            if (count != 0)
                            {
                                count--;
                                tempString += s[i];
                            }
                            else
                            {
                                string tempResult = decodeString(tempString);
                                while (times > 0)
                                {
                                    result += tempResult;
                                    times--;
                                }
                                timeString = "";
                                break;
                            }
                        }
                        else
                        {
                            tempString += s[i];
                        }

                        i++;
                    }
                }
                else
                {
                    result += s[i];
                }
            }

            return result;
        }
};

int main()
{
    Solution solution;

    string s = "3[a2[c]]";

    string result = solution.decodeString(s);

    cout << result << endl;

    return 0;
}