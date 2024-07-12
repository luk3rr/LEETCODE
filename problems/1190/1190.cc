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
#include <stack>

class Solution
{
    private:
        std::string reverse(std::string s)
        {
            std::string rev;

            for (std::size_t i = s.size(); i > 0; --i)
            {
                rev += s[i - 1];
            }

            return rev;
        }

    public:
        std::string reverseParentheses(std::string s)
        {
            std::stack<std::string> stack;
            std::string current;

            for (char c : s)
            {
                if (c == '(')
                {
                    stack.push(current);
                    current = "";
                }
                else if (c == ')')
                {
                    std::string top = stack.top();
                    stack.pop();
                    top += reverse(current);
                    current = top;
                }
                else
                {
                    current += c;
                }
            }

            return current;
        }
};
