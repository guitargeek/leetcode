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

  // 13. Roman to Integer
  int romanToInt(std::string s);

  // 15. 3Sum
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

  // 70 Climbing Stairs
  int climbStairs(int n);

  // 155. Min Stack
  class MinStack;

  // 162. Find Peak Element
  int findPeakElement(std::vector<int>& v);

  // 200. Number of Islands
  int numIslands(std::vector<std::vector<char>>& grid);

  // 206. Reverse Linked List
  ListNode* reverseList(ListNode* head);

  // 461. Hamming Distance
  int hammingDistance(int x, int y);

  // 621. Task Scheduler
  int leastInterval(std::vector<char>& tasks, int n);

  // 938. Range Sum of BST
  int rangeSumBST(TreeNode* root, int L, int R);

  // 977. Squares of a Sorted Array
  std::vector<int> sortedSquares(std::vector<int>& A);

  // 1037. Valid Boomerang
  bool isBoomerang(std::vector<std::vector<int>>& points);

  // 1046. Last Stone Weight
  int lastStoneWeight(std::vector<int>& stones);

  // 1042. Flower Planting With No Adjacent
  std::vector<int> gardenNoAdj(int N, std::vector<std::vector<int>>& paths);

}  // namespace leet

#endif
