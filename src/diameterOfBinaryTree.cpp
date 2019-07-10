/**

543. Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the
length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. 

*/

#include "leet.h"

namespace leet {

    using namespace std;

    namespace {
        int recurse(TreeNode* root, int& maximum) {
            if (root == NULL)
                return 0;
            int left = 0;
            int right = 0;
            if (root->left)
                left = recurse(root->left, maximum) + 1;
            if (root->right)
                right = recurse(root->right, maximum) + 1;

            maximum = max(maximum, left + right);
            return max(left, right);
        }
    }  // namespace

    int diameterOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        recurse(root, maximum);
        return maximum;
    }

}  // namespace leet
