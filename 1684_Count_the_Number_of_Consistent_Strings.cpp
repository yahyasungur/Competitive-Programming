/*
LeetCode 1684. Count the Number of Consistent Strings Problem Solution
Problem Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/

Author: Yahya Sungur
Date: 09/12/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    int numberOfConsistentString = 0;

    for (size_t i = 0; i < words.size(); i++)
    {
        // Check if all characters of string allowed present in strings
        string word = words[i];
        numberOfConsistentString++;

        for (size_t j = 0; j < word.size(); j++)
        {
            int index = allowed.find_first_of(word[j]);
            if ( index >= allowed.size() || index < 0 )
            {
                numberOfConsistentString--;
                break;
            }
        }
    }
    
    return numberOfConsistentString;
}

// int countConsistentStrings(string allowed, vector<string>& words) {
//     unordered_set<char> allowedSet(allowed.begin(), allowed.end());
//     int count = 0;

//     for (const string& word : words) {
//         bool isConsistent = true;
//         for (char c : word) {
//             if (allowedSet.find(c) == allowedSet.end()) {
//                 isConsistent = false;
//                 break;
//             }
//         }

//         if (isConsistent) {
//             count++;
//         }
//     }

//     return count;
// }

// int countConsistentStrings(string allowed, vector<string>& words) {
//     int numberOfConsistentString = 0;
//     set<char> allowedSet(allowed.begin(), allowed.end());

//     for (size_t i = 0; i < words.size(); i++)
//     {
//         // Check if all characters of string allowed present in strings
//         string word = words[i];
//         numberOfConsistentString++;

//         for (size_t j = 0; j < word.size(); j++)
//         {
//             if ( allowedSet.find(word[j]) == allowedSet.end() )
//             {
//                 numberOfConsistentString--;
//                 break;
//             }
//         }
//     }
    
//     return numberOfConsistentString;
// }

// int countConsistentStrings(string allowed, vector<string>& words) {
//     int numberOfConsistentString = 0;
//     vector<bool> allowedChars(26, false);

//     for (size_t i = 0; i < allowed.size(); i++)
//     {
//         allowedChars[allowed[i] - 'a'] = true;
//     }

//     for (size_t i = 0; i < words.size(); i++)
//     {
//         // Check if all characters of string allowed present in strings
//         string word = words[i];
//         numberOfConsistentString++;

//         for (size_t j = 0; j < word.size(); j++)
//         {
//             if ( !allowedChars[word[j] - 'a'] )
//             {
//                 numberOfConsistentString--;
//                 break;
//             }
//         }
//     }
    
//     return numberOfConsistentString;
// }

int main()
{
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    cout << countConsistentStrings("ab", words) << endl;
    return 0;
}