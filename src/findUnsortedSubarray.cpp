/**

581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order,
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

```
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

Note:

  1. Then length of the input array is in range [1, 10,000].
  2. The input array may contain duplicates, so ascending order here means <=.

*/

#include "leet.h"

namespace leet {

    using namespace std;

    int findUnsortedSubarray(vector<int> const& nums) {
        if (nums.size() < 2)
            return 0;

        int a = -1;
        int b = -1;

        int submin = -1;
        int submax = -1;

        bool t = false;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] < nums[i] || t && nums[i + 1] < submax) {
                if (!t) {
                    submin = min(nums[i], nums[i + 1]);
                    submax = max(nums[i], nums[i + 1]);
                    a = i;
                } else {
                    submin = min(min(submin, nums[i]), nums[i + 1]);
                    submax = max(max(submax, nums[i]), nums[i + 1]);
                }
                b = i + 2;
                t = true;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > submin) {
                a = min(i, a);
            }
        }

        return b - a;
    }

}  // namespace leet
