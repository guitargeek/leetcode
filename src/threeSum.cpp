/**

15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets
in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

```
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

*/

#include "leet.h"

#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>

namespace leet {

  using namespace std;

  using Bitset = bitset<96>;

  const Bitset b1(
      string("000000000000000000000000000000000000000000000000000000000000000011111111111111111111111111111111"));
  const Bitset b2(
      string("000000000000000000000000000000001111111111111111111111111111111100000000000000000000000000000000"));
  const Bitset b3(
      string("111111111111111111111111111111110000000000000000000000000000000000000000000000000000000000000000"));

  vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> indexMap;

    unordered_set<Bitset> hashMap;
    vector<vector<int>> triplets;

    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] <= 0)
        indexMap[nums[i]] = i;
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < 0)
        break;
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] + 2 * nums[j] < 0)
          break;

        auto got = indexMap.find(-nums[i] - nums[j]);
        if (got != indexMap.end() && got->second < j) {
          int a = nums[got->second];
          int b = nums[j];
          int c = nums[i];

          Bitset u = (Bitset(a) & b1) | ((Bitset(b) << 32) & b2) | ((Bitset(c) << 64) & b3);
          if (hashMap.find(u) != hashMap.end())
            continue;

          triplets.push_back({a, b, c});

          hashMap.insert(u);
        }
      }
    }

    return triplets;
  }

}  // namespace leet
