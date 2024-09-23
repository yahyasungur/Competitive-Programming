/*
LeetCode 1071. Greatest Common Divisor of Strings
Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings

Author: Yahya Sungur
Date: 09/23/2024
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 

    // base case 
    if (a == b) 
        return a; 

    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
}

string gcdOfStrings(string str1, string str2) 
{
    if (str1[0] != str2[0])
    {
        return "";
    }

    if (str1.size() < str2.size()) // Make str1 longer
    {
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    
    for (size_t i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i % str2.size()])
        {
            return "";
        }
    }

    int gcdOfSizes = gcd(str1.size(), str2.size());
    
    for (size_t i = gcdOfSizes; i < str2.size(); i += gcdOfSizes)
    {
        for (size_t j = 0; j < gcdOfSizes; j++)
        {
            if (str2[i+j] != str2[j])
            {
                return "";
            }
            
        }
    }
    
    return str2.substr(0,gcdOfSizes);
}

int main()
{
    string result = gcdOfStrings("AABBAABBAA", "AABB");
    cout << result << endl;
    return 0;
}