/*
LeetCode 735. Asteroid Collision
Author: Yahya Sungur
Date: 04/09/2025
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> currentAsteroids;
        int lastAsteroid;

        for (size_t i = 0; i < asteroids.size(); i++)
        {
            while (true)
            {
                if (currentAsteroids.empty())
                {
                    currentAsteroids.push(asteroids[i]);
                    break;
                }
                
                lastAsteroid = currentAsteroids.top();

                if (lastAsteroid * asteroids[i] < 0)
                {
                    if (lastAsteroid < 0)
                    {
                        // Distance between them is increasing
                        currentAsteroids.push(asteroids[i]);
                        break;
                    }
                    else
                    {
                        // Distence between them is decreasing
                        if (lastAsteroid + asteroids[i] < 0)
                        {
                            currentAsteroids.pop();
                        }
                        else if (lastAsteroid + asteroids[i] == 0)
                        {
                            currentAsteroids.pop();
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    currentAsteroids.push(asteroids[i]);
                    break;
                }
            }
        }

        asteroids.clear();
        
        while (!currentAsteroids.empty())
        {
            asteroids.insert(asteroids.begin(), currentAsteroids.top());
            currentAsteroids.pop();
        }
        
        return asteroids;
    }
};

int main()
{
    Solution solution;

    vector<int> asteroids = {5,10,-5};

    vector<int> result = solution.asteroidCollision(asteroids);

    for (auto &&num : result)
    {
        cout << num << ",";
    }

    return 0;
}