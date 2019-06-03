#ifndef leet_h
#define leet_h

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

  //
  // Functions which provide the actual problem solutions
  //

  // 1. Two Sum
  std::vector<int> twoSum(std::vector<int>& nums, int target);

  // 2. Add Two Numbers
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

  // 155. Min Stack
  class MinStack;

  // 200. Number of Islands
  int numIslands(std::vector<std::vector<char>>& grid);

  // 206. Reverse Linked List
  ListNode* reverseList(ListNode* head);

  // 461. Hamming Distance
  int hammingDistance(int x, int y);

  // 1037. Valid Boomerang
  bool isBoomerang(std::vector<std::vector<int>>& points);

  // 1046. Last Stone Weight
  int lastStoneWeight(std::vector<int>& stones);

}  // namespace leet

#endif
