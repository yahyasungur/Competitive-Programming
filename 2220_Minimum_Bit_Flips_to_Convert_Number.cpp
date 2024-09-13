/*
LeetCode 1684. Count the Number of Consistent Strings Problem Solution
Problem Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number

Author: Yahya Sungur
Date: 09/13/2024
*/

#include <iostream>

using namespace std;

int minBitFlips(int start, int goal) {
    if (start == goal)
    {
        return 0;
    }
    
    // Make XOR operation and get the number in binary representation, then count the number of 1's
    int diff = start ^ goal;

    int requiredFlip = 0;
    for (long i = (1 << 30); i > 0 ; i /= 2)
    {
        if ((diff & i) != 0)
        {
            requiredFlip++;
        }
    }

    return requiredFlip;
}

int main()
{
    cout << minBitFlips (10,7) << endl;
    return 0;
}