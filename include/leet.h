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

    // 4. Median of Two Sorted Arrays
    double findMedianSortedArrays(std::vector<int> const& nums1, std::vector<int> const& nums2);

    // 7. Reverse Integer
    int reverse(int x);

    // 13. Roman to Integer
    int romanToInt(std::string s);

    // 14. Longest Common Prefix
    std::string longestCommonPrefix(std::vector<std::string>& strs);

    // 15. 3Sum
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

    // 20. Valid Parentheses
    bool isValid(std::string const& s);

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates(std::vector<int>& nums);

    // 53. Maximum Subarray
    int maxSubArray(std::vector<int>& nums);

    // 70. Climbing Stairs
    int climbStairs(int n);

    // 128. Longest Consecutive Sequence
    int longestConsecutive(std::vector<int>& nums);

    // 136. Single Number
    int singleNumber(std::vector<int> const& nums);

    // 155. Min Stack
    class MinStack;

    // 162. Find Peak Element
    int findPeakElement(std::vector<int>& v);

    // 191. Number of 1 Bits
    int hammingWeight(uint32_t n);

    // 198. House Robber
    int rob(std::vector<int>& nums);

    // 200. Number of Islands
    int numIslands(std::vector<std::vector<char>>& grid);

    // 206. Reverse Linked List
    ListNode* reverseList(ListNode* head);

    // 226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root);

    // 234. Palindrome Linked List
    bool isPalindrome(ListNode* head);

    // 258. Add Digits
    int addDigits(int num);

    // 287. Find the Duplicate Number
    int findDuplicate(std::vector<int>& nums);

    // 292. Nim Game
    bool canWinNim(int n);

    // 338. Counting Bits
    std::vector<int> countBits(int num);

    // 397. Integer Replacement
    int integerReplacement(int n);

    // 448. Find All Numbers Disappeared in an Array
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums);

    // 461. Hamming Distance
    int hammingDistance(int x, int y);

    // 509. Fibonacci Number
    int fib(int N);

    // 538. Convert BST to Greater Tree
    TreeNode* convertBST(TreeNode* root);

    // 543. Diameter of Binary Tree
    int diameterOfBinaryTree(TreeNode* root);

    // 566. Reshape the Matrix
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c);

    // 581. Shortest Unsorted Continuous Subarray
    int findUnsortedSubarray(std::vector<int> const& nums);

    // 617. Merge Two Binary Trees
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

    // 621. Task Scheduler
    int leastInterval(std::vector<char>& tasks, int n);

    // 693. Binary Number with Alternating Bits
    bool hasAlternatingBits(int n);

    // 709. To Lower Case
    std::string toLowerCase(std::string str);

    // 705. Design HashSet
    class MyHashSet;

    // 706. Design HashMap
    class MyHashMap;

    // 771.  Jewels and Stones
    int numJewelsInStones(std::string const& J, std::string const& S);

    // 784. Letter Case Permutation
    std::vector<std::string> letterCasePermutation(std::string const& s);

    // 812. Largest Triangle Area
    double largestTriangleArea(std::vector<std::vector<int>>& p);

    // 824. Goat Latin
    std::string toGoatLatin(std::string const& s);

    // 832. Flipping an Image
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A);

    // 852. Peak Index in a Mountain Array
    int peakIndexInMountainArray(std::vector<int>& A);

    // 896. Monotonic Array
    bool isMonotonic(std::vector<int> const& a);

    // 937. Reorder Log Files
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs);

    // 917. Reverse Only Letters
    std::string reverseOnlyLetters(std::string s);

    // 938. Range Sum of BST
    int rangeSumBST(TreeNode* root, int L, int R);

    // 976. Largest Perimeter Triangle
    int largestPerimeter(std::vector<int>& a);

    // 977. Squares of a Sorted Array
    std::vector<int> sortedSquares(std::vector<int>& A);

    // 984. String Without AAA or BBB
    std::string strWithout3a3b(int A, int B);

    // 1009. Complement of Base 10 Integer
    int bitwiseComplement(int n);

    // 1013. Partition Array Into Three Parts With Equal Sum
    bool canThreePartsEqualSum(std::vector<int>& a);

    // 1021. Remove Outermost Parentheses
    std::string removeOuterParentheses(std::string S);

    // 1022. Sum of Root To Leaf Binary Numbers
    int sumRootToLeaf(TreeNode* root);

    // 1029. Two City Scheduling
    int twoCitySchedCost(std::vector<std::vector<int>>& costs);

    // 1030. Matrix Cells in Distance Order
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);

    // 1033. Moving Stones Until Consecutive
    std::vector<int> numMovesStones(int a, int b, int c);

    // 1037. Valid Boomerang
    bool isBoomerang(std::vector<std::vector<int>>& points);

    // 1042. Flower Planting With No Adjacent
    std::vector<int> gardenNoAdj(int N, std::vector<std::vector<int>>& paths);

    // 1046. Last Stone Weight
    int lastStoneWeight(std::vector<int>& stones);

    // 1047. Remove All Adjacent Duplicates In String
    std::string removeDuplicates(std::string const& str);

    // 1078. Occurrences After Bigram
    std::vector<std::string> findOcurrences(std::string const& text,
                                            std::string const& first,
                                            std::string const& second);

    // 1089. Duplicate Zeros
    void duplicateZeros(std::vector<int>& arr);

    // 1108. Defanging an IP Address
    std::string defangIPaddr(std::string address);

    // 1114. Print in Order
    class Foo;

    // 1122. Relative Sort Array
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2);

    // 1128. Number of Equivalent Domino Pairs
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes);

}  // namespace leet

#endif
