/*
LeetCode 649. Dota2 Senate
Author: Yahya Sungur
Date: 04/21/2025
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int getIndex(string s, char c, int iter)
        {
            while (iter < s.size())
            {
                if (s[iter] == c)
                {
                    return iter;
                }
                iter++;
            }
            return -1;
        }

        string predictPartyVictory(string senate) {
            int R_index = -1, D_index = -1, iter = 0;

            if (senate[0] == 'R')
            {
                R_index = 0;
                D_index = getIndex(senate, 'D', 1);
            }
            else
            {
                D_index = 0;
                R_index= getIndex(senate, 'R', 1);
            }

            if (R_index < 0)
            {
                return "Dire";
            }
            else if (D_index < 0)
            {
                return "Radiant";
            }
            
            while (iter < senate.size())
            {
                if (senate[iter] == 'R')
                {
                    D_index = getIndex(senate, 'D', iter+1);
                    D_index = D_index < 0 ? getIndex(senate, 'D', 0) : D_index;

                    if (D_index < 0)
                    {
                        return "Radiant"; 
                    }

                    senate[D_index] = 'X';
                }
                else if (senate[iter] == 'D')
                {
                    R_index = getIndex(senate, 'R', iter+1);
                    R_index = R_index < 0 ? getIndex(senate, 'R', 0) : R_index;

                    if (R_index < 0)
                    {
                        return "Dire"; 
                    }

                    senate[R_index] = 'X';
                }
                iter++;
            }
            
            R_index = 0;
            D_index = 0;

            string tempSenate = "";
            for (auto &&i : senate)
            {
                if (i == 'R')
                {
                    R_index++;
                    tempSenate += i;
                }
                else if (i == 'D')
                {
                    D_index++;
                    tempSenate += i;
                }
            }

            if (R_index <= 0)
            {
                return "Dire";
            }
            else if (D_index <= 0)
            {
                return "Radiant";
            }
            else
            {
                return predictPartyVictory(tempSenate);
            }
        }
};

int main()
{
    Solution solution;

    string s = "DRRDRDRDRDDRDRDR";

    string result = solution.predictPartyVictory(s);

    cout << result << endl;

    return 0;
}