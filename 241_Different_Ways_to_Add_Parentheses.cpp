/*
LeetCode 241. Different Ways to Add Parentheses
Problem Link: https://leetcode.com/problems/different-ways-to-add-parentheses

Author: Yahya Sungur
Date: 09/19/2024
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> diffWaysToCompute(string expression) 
{
    vector<int> results;

    // Check how many operators string have
    vector<int> operatorLocations;
    for (size_t i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            operatorLocations.push_back(i);
        }
    }

    if (operatorLocations.size() == 0)
    {
        results.push_back(atoi(expression.c_str()));
    }
    else if (operatorLocations.size() == 1)
    {
        // Evaluate expression
        int index = operatorLocations[0];

        int first = atoi(expression.substr(0,index).c_str());
        int second = atoi(expression.substr(index+1, expression.size()-index-1).c_str());

        int result;
        switch (expression[index])
        {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
        default:
            result = first * second;
            break;
        }

        results.push_back(result);
    }
    else
    {
        for (size_t i = 0; i < operatorLocations.size(); i++)
        {
            int index = operatorLocations[i];
            string first = expression.substr(0,index);
            string second = expression.substr(index+1, expression.size()-index-1);

            int result;

            vector<int> firstResults = diffWaysToCompute(first);
            vector<int> secondResults = diffWaysToCompute(second);

            switch (expression[index])
            {
                case '+':
                {
                    for (size_t i = 0; i < firstResults.size(); i++)
                    {
                        for (size_t j = 0; j < secondResults.size(); j++)
                        {
                            result = firstResults[i] + secondResults[j];
                            results.push_back(result);
                        }
                    }
                    break;
                }
                case '-':
                {
                    for (size_t i = 0; i < firstResults.size(); i++)
                    {
                        for (size_t j = 0; j < secondResults.size(); j++)
                        {
                            result = firstResults[i] - secondResults[j];
                            results.push_back(result);
                        }
                    }
                    break;
                }
                case '*':
                default:
                {
                    for (size_t i = 0; i < firstResults.size(); i++)
                    {
                        for (size_t j = 0; j < secondResults.size(); j++)
                        {
                            result = firstResults[i] * secondResults[j];
                            results.push_back(result);
                        }
                    }
                    break;
                }
            }
        }
    }

    return results;
}

int main()
{
    vector<int> outputs = diffWaysToCompute("2*3-4*5");

    for (size_t i = 0; i < outputs.size(); i++)
    {
        cout << outputs[i] << "," <<  endl;
    }

    return 0;
}