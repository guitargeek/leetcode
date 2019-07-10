/**

1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

*/

#include "leet.h"

#include <vector>
#include <unordered_map>

namespace leet {

    using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        vector<int> indices{-1, -1};

        for (int i = 0; i < nums.size(); ++i) {
            auto got = indexMap.find(target - nums[i]);
            if (got != indexMap.end()) {
                indices[1] = i;
                indices[0] = got->second;
                break;
            }
            indexMap[nums[i]] = i;
        }

        return indices;
    }

}  // namespace leet
