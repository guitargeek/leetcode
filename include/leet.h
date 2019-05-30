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
  // 206. Reverse Linked List
  ListNode* reverseList(ListNode* head);

}  // namespace leet

#endif
