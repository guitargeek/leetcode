/**

448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

*/

#include "leet.h"

namespace leet {

    using namespace std;

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int k = 0; k < nums.size(); ++k) {
            int i = k;
            int prev = 1;
            bool first = true;
            while (nums[i]) {
                prev = nums[i];
                if (!first)
                    nums[i] = 0;
                i = prev - 1;
                first = false;
            }
        }
        vector<int> out;
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k])
                out.push_back(k + 1);
        }
        return out;
    }

}  // namespace leet
