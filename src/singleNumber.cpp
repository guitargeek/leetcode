/**

136. Single Number

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

```
Input: [2,2,1]
Output: 1
```

Example 2:

```
Input: [4,1,2,1,2]
Output: 4
```

*/

#include "leet.h"

namespace leet {

    int singleNumber(std::vector<int>& nums) {
        int single = 0;
        for (int x : nums) {
            single ^= x;
        }
        return single;
    }

}  // namespace leet
