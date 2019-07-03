#ifndef leet_h
#define leet_h

#include <string>
#include <vector>

namespace leet {

  ///
  // Data structures required for the problems
  //

  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
  };

  struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  //
  // Functions which provide the actual problem solutions
  //

  // 1. Two Sum
  std::vector<int> twoSum(std::vector<int>& nums, int target);

  // 2. Add Two Numbers
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  // 3. Longest Substring Without Repeating Characters
  int lengthOfLongestSubstring(std::string s);

  // 7. Reverse Integer
  int reverse(int x);

  // 13. Roman to Integer
  int romanToInt(std::string s);

  // 14. Longest Common Prefix
  std::string longestCommonPrefix(std::vector<std::string>& strs);

  // 15. 3Sum
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

  // 70. Climbing Stairs
  int climbStairs(int n);

  // 128. Longest Consecutive Sequence
  int longestConsecutive(std::vector<int>& nums);

  // 155. Min Stack
  class MinStack;

  // 162. Find Peak Element
  int findPeakElement(std::vector<int>& v);

  // 198. House Robber
  int rob(std::vector<int>& nums);

  // 200. Number of Islands
  int numIslands(std::vector<std::vector<char>>& grid);

  // 206. Reverse Linked List
  ListNode* reverseList(ListNode* head);

  // 461. Hamming Distance
  int hammingDistance(int x, int y);

  // 509. Fibonacci Number
  int fib(int N);

  // 543. Diameter of Binary Tree
  int diameterOfBinaryTree(TreeNode* root);

  // 617. Merge Two Binary Trees
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

  // 621. Task Scheduler
  int leastInterval(std::vector<char>& tasks, int n);

  // 832. Flipping an Image
  std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A);

  // 852. Peak Index in a Mountain Array
  int peakIndexInMountainArray(std::vector<int>& A);

  // 938. Range Sum of BST
  int rangeSumBST(TreeNode* root, int L, int R);

  // 977. Squares of a Sorted Array
  std::vector<int> sortedSquares(std::vector<int>& A);

  // 1021. Remove Outermost Parentheses
  std::string removeOuterParentheses(std::string S);

  // 1033. Moving Stones Until Consecutive
  std::vector<int> numMovesStones(int a, int b, int c);

  // 1037. Valid Boomerang
  bool isBoomerang(std::vector<std::vector<int>>& points);

  // 1042. Flower Planting With No Adjacent
  std::vector<int> gardenNoAdj(int N, std::vector<std::vector<int>>& paths);

  // 1046. Last Stone Weight
  int lastStoneWeight(std::vector<int>& stones);

  // 1089. Duplicate Zeros
  void duplicateZeros(std::vector<int>& arr);

}  // namespace leet

#endif
