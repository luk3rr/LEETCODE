/*
 * Filename: 2582.cc
 * Created on: July  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Problem: Pass the Pillow
 * - https://leetcode.com/problems/pass-the-pillow
 */

#include <cmath>

class Solution
{
    public:
        int passThePillow(int n, int time)
        {
            if (n == time)
                return n - 1;

            if (n > time)
                return time + 1;

            int numTravel = time / (n - 1);

            int remainingTime = time % (n - 1);

            if (numTravel % 2 == 0)
                return  remainingTime + 1;

            else
                return n -  remainingTime;
        }
};
