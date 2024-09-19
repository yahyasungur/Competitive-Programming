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

vector<int> results;

int evaluatePossibleScenariosRecursively(string expression, int operatorNumber)
{
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
        return atoi(expression.c_str());
    }
    else if (operatorLocations.size() == 1)
    {
        // Evaluate expression
        int index = operatorLocations[0];

        int first = atoi(expression.substr(0,index).c_str());
        int second = atoi(expression.substr(index+1, expression.size()-index-1).c_str());

        switch (expression[index])
        {
        case '+':
            return first + second;
            break;
        case '-':
            return first - second;
        case '*':
        default:
            return first*second;
            break;
        }
    }
    else
    {
        for (size_t i = 0; i < operatorLocations.size(); i++)
        {
            int index = operatorLocations[i];
            string first = expression.substr(0,index);
            string second = expression.substr(index+1, expression.size()-index-1);

            int result;
            switch (expression[index])
            {
            case '+':
                result = evaluatePossibleScenariosRecursively(first, operatorNumber) + evaluatePossibleScenariosRecursively(second, operatorNumber);
                break;
            case '-':
                result = evaluatePossibleScenariosRecursively(first, operatorNumber) - evaluatePossibleScenariosRecursively(second, operatorNumber);
                break;
            case '*':
            default:
                result = evaluatePossibleScenariosRecursively(first, operatorNumber) * evaluatePossibleScenariosRecursively(second, operatorNumber);
                break;
            }

            if (operatorLocations.size() == operatorNumber)
            {
                // Add result to set
                results.push_back(result);
            }
            else
            {
                return result;
            }
        }
    }

    return 0;
}

vector<int> diffWaysToCompute(string expression) 
{
    int operatorNumber = 0;
    for (size_t i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            operatorNumber++;
        }
    }

    evaluatePossibleScenariosRecursively(expression, operatorNumber);
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