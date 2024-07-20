/*
 * Filename: 2096.cc
 * Created on: July 16, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * Problem: Step by Step Directions from a Binary Tree Node to Another
 * -
 * https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another
 */

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

struct TreeNode
{
        int       val;
        TreeNode* left;
        TreeNode* right;

        TreeNode()
            : val(0),
              left(nullptr),
              right(nullptr)
        { }

        TreeNode(int x)
            : val(x),
              left(nullptr),
              right(nullptr)
        { }

        TreeNode(int x, TreeNode* left, TreeNode* right)
            : val(x),
              left(left),
              right(right)
        { }
};

struct TreeWalk
{
        TreeNode* node;
        char      direction;

        TreeWalk(TreeNode* node, char direction)
            : node(node),
              direction(direction)
        { }
};

class Solution
{
    private:
        TreeNode* Find(TreeNode* node, const int& goal, std::vector<TreeWalk>& path)
        {
            if (node == nullptr)
                return nullptr;

            if (node->val == goal)
            {
                path.push_back({ node, ' ' });
                return node;
            }

            path.push_back({ node, 'L' });
            TreeNode* left = this->Find(node->left, goal, path);

            if (left != nullptr)
                return left;

            // Remove the step if the left search didn't find the goal
            path.pop_back();

            path.push_back({ node, 'R' });
            TreeNode* right = this->Find(node->right, goal, path);

            if (right != nullptr)
                return right;

            // Remove the step if the right search didn't find the goal
            path.pop_back();

            return nullptr;
        }

    public:
        std::string getDirections(TreeNode* root, int startValue, int destValue)

        {
            // Find the path from the root to the start and destination nodes
            std::vector<TreeWalk> startPath;
            Find(root, startValue, startPath);

            std::vector<TreeWalk> destPath;
            Find(root, destValue, destPath);

            std::cout << std::endl;

            // Find the index of the root of the subtree that contains both nodes
            std::size_t rootSubtreeIndex = 0;

            for (std::size_t i = 0; i < std::min(startPath.size(), destPath.size());
                 i++)
            {
                if (startPath[i].node->val == destPath[i].node->val)
                    rootSubtreeIndex = i;
            }

            // Build the path from the start node to the destination node
            std::string path;

            path.append(startPath.size() - rootSubtreeIndex - 1, 'U');

            for (std::size_t i = rootSubtreeIndex; i < destPath.size(); i++)
                path += destPath[i].direction;

            path.pop_back();

            return path;
        }
};
