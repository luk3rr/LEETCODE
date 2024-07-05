/*
 * Filename: 1.cc
 * Created on: July  5, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Description: Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 *  - https://leetcode.com/problems/two-sum
 */

#include "unordered_map"
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, std::size_t> umap;

            for (std::size_t i = 0; i < nums.size(); i++)
            {
                int complement = target - nums[i];

                if (umap.contains(complement))
                {
                    return {int(i), int(umap.at(complement))};
                }

                umap.insert(std::make_pair(nums[i], i));
            }

            return {};
        }
};
