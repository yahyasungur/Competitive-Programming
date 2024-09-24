/*
LeetCode 605. Can Place Flowers
Problem Link: https://leetcode.com/problems/can-place-flowers

Author: Yahya Sungur
Date: 09/24/2024
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if (n == 0)
        {
            return true;
        }

        if (flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && n == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        // first index
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            n--;
        }

        if (n <= 0)
        {
            return true;
        }
        

        // last index
        if (flowerbed[flowerbed.size()-2] == 0 && flowerbed[flowerbed.size()-1] == 0)
        {
            flowerbed[flowerbed.size()-1] = 1;
            n--;
        }
        
        if (n <= 0)
        {
            return true;
        }

        for (size_t i = 1; i < flowerbed.size()-1; i++)
        {
            if (flowerbed[i] == 1)
            {
                continue;
            }
            else if ((i-1 >= 0) && (flowerbed[i-1] == 0) && ((i+1) < flowerbed.size()) && (flowerbed[i+1] == 0))
            {
                flowerbed[i] = 1;
                n--;

                if (n <= 0)
                {
                    return true;
                }
            }
        }

        return (n <= 0);
    }
};

int main()
{
    Solution solution;

    vector<int> flowerbed = {1,0,0,0,1};
    int n = 2;

    bool result = solution.canPlaceFlowers(flowerbed, n);

    cout << result << endl;

    return 0;
}