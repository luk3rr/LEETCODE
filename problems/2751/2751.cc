/*
 * Filename: 2751.cc
 * Created on: July 13, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Robot Collisions
 * - https://leetcode.com/problems/robot-collisions/
 */

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

class Solution
{
    public:
        std::vector<int> survivedRobotsHealths(std::vector<int>& positions,
                                               std::vector<int>& healths,
                                               std::string       directions)
        {

            std::vector<int> indices(positions.size());

            for (std::size_t i = 0; i < positions.size(); i++)
                indices[i] = i;

            std::sort(indices.begin(), indices.end(), [&positions](int i, int j) {
                return positions[i] < positions[j];
            });

            std::stack<int> stack;

            for (int index : indices)
            {
                if (directions[index] == 'R')
                {
                    stack.push(index);
                }
                else
                {
                    while (not stack.empty() and healths[index] > 0)
                    {

                        int top = stack.top();
                        stack.pop();

                        if (healths[top] > healths[index])
                        {
                            healths[top] -= 1;
                            healths[index] = 0;

                            stack.push(top);
                        }
                        else if (healths[top] < healths[index])
                        {
                            healths[top] = 0;
                            healths[index] -= 1;
                        }
                        else
                            healths[top] = healths[index] = 0;
                    }
                }
            }
            std::vector<int> result;

            for (std::size_t i = 0; i < healths.size(); i++)
                if (healths[i] > 0)
                    result.push_back(healths[i]);

            return result;
        }
};
