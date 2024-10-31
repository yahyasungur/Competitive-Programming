/*
LeetCode 2352. Equal Row and Column Pairs
Problem Link: https://leetcode.com/problems/equal-row-and-column-pairs

Author: Yahya Sungur
Date: 10/31/2024
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int size = grid.size();
        int result = 0;

        map<vector<int>, int> gridMap;
        vector<int> columnVec;

        for (auto &&vec : grid)
        {
            gridMap[vec]++;
        }

        for (size_t c = 0; c < size; c++)
        {
            for (size_t r = 0; r < size; r++)
            {
                columnVec.push_back(grid[r][c]);
            }
            
            result += gridMap[columnVec];
            columnVec.clear(); 
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};

    int result = solution.equalPairs(grid);

    cout << result << endl;

    return 0;
}