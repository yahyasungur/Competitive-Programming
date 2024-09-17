/*
LeetCode 884. Uncommon Words from Two Sentences
Problem Link: https://leetcode.com/problems/uncommon-words-from-two-sentences

Author: Yahya Sungur
Date: 09/13/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

size_t min( size_t first, size_t second )
{
    if (first <= second )
    {
        return first;
    }
    else
    {
        return second;
    }
}

void splitString(const string str, vector<string> &vector, char token)
{
    size_t pos = str.find(token);
    size_t initialPos = 0;
    vector.clear();

    while (pos != string::npos)
    {
        vector.push_back( str.substr( initialPos, pos - initialPos ));
        initialPos = pos + 1;
        pos = str.find( token , initialPos );
    }

    vector.push_back( str.substr(initialPos, min(pos, str.size()) - initialPos ));
}

vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> uncommonWords;
    map<string, int> wordCountMap;

    // Split s1 at spaces
    vector<string> s1Words;
    splitString(s1 + " " + s2, s1Words, ' ');

    for (auto s1Word : s1Words)
    {
        if (wordCountMap.count(s1Word))
        {
            wordCountMap[s1Word] += 1;
        }
        else
        {
            wordCountMap[s1Word] = 1;
        }
    }
    
    // Check the words occurs once
    for ( auto &item : wordCountMap )
    {
        if (item.second == 1)
        {
            uncommonWords.push_back(item.first);
        }
    }
    
    return uncommonWords;
}

int main()
{
    string s1 = "this apple is sweet", s2 = "this apple is sour";
    vector<string> uncommonWords = uncommonFromSentences(s1,s2);
    
    for (auto &word : uncommonWords )
    {
        cout << word + " ," << endl;
    }

    return 0;
}