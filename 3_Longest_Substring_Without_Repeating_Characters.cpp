#include <iostream>
#include <string>
#include <unordered_map>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 0){
            return 0;
        }

        int begin = 0, end = 0, stringLenth = s.size();
        int substringLengthMax = 0;
        unordered_map<char, int> charIndex;

        while(end < stringLenth){
            if(charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= begin){
                begin = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end;
            substringLengthMax = max(substringLengthMax, end - begin + 1);
            end++;
        }

        return substringLengthMax;
    }
};

int main()
{
    string s;
    Solution sol;

    cin >> s;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}