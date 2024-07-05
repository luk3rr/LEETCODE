/*
 * Filename: 2108.cc
 * Created on: July  5, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Problem: Find First Palindromic String in the Array
 * - https://leetcode.com/problems/find-first-palindromic-string-in-the-array
 */

#include <string>
#include <vector>

class Solution
{
    private:
        bool isPalindrome(const std::string& word)
        {
            int i = 0;
            int j = word.size() - 1;
            while (i < j)
            {
                if (word[i] != word[j])
                {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }

    public:
        std::string firstPalindrome(std::vector<std::string>& words)
        {
            for (const std::string& word : words)
            {
                if (this->isPalindrome(word))
                {
                    return word;
                }
            }
            return "";
        }
};
