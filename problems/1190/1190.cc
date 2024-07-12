/*
 * Filename: 1190.cc
 * Created on: July 11, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Reverse Substrings Between Each Pair of Parentheses
 * - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 */

#include <cstddef>
#include <string>

class Solution
{
    private:
        std::string reverse(std::string s)
        {
            std::string rev;

            for (std::size_t i = s.size(); i > 0; --i)
            {
                rev += s.at(i);
            }

            return rev;
        }

    public:
        std::string reverseParentheses(std::string s)
        {

        }
};
