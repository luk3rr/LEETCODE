/*
 * Filename: 2058.cc
 * Created on: July  5, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * - https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
 */

#include <vector>

struct ListNode
{
        int       val;
        ListNode* next;

        ListNode()
            : val(0),
              next(nullptr)
        { }

        ListNode(int x)
            : val(x),
              next(nullptr)
        { }

        ListNode(int x, ListNode* next)
            : val(x),
              next(next)
        { }
};

class Solution
{
    public:
        std::vector<int> nodesBetweenCriticalPoints(ListNode* head)
        {
            ListNode* prev = head;
            ListNode* curr = head->next;

            // Check if the list has at least 3 elements
            if (not(curr and curr->next))
                return { -1, -1 };

            std::size_t lastCriticalPoint  = 0;
            std::size_t firstCriticalPoint = 0;

            std::size_t currIndex   = 2;
            int         minDistance = 0;

            while (curr)
            {
                // Check if is a local maxima or local minima
                if ((prev->val < curr->val and curr->next and
                     curr->val > curr->next->val) or
                    (prev->val > curr->val and curr->next and
                     curr->val < curr->next->val))
                {
                    // Calculate the min distance
                    if ((minDistance == 0 and lastCriticalPoint != 0) or
                        (currIndex - lastCriticalPoint < minDistance))
                        minDistance = currIndex - lastCriticalPoint;

                    lastCriticalPoint = currIndex;

                    // Set the first critical point
                    if (firstCriticalPoint == 0)
                        firstCriticalPoint = currIndex;
                }

                currIndex++;
                prev = curr;
                curr = curr->next;
            }

            // Check if there is more than one critical point
            if (lastCriticalPoint == 0 or firstCriticalPoint == lastCriticalPoint)
                return { -1, -1 };

            int maxDistance = lastCriticalPoint - firstCriticalPoint;

            return { minDistance, maxDistance };
        }
};
