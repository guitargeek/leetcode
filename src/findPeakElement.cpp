/**

166. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

Example 2:

```
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
```

Note:

Your solution should be in logarithmic complexity.

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    namespace {
        int findPeakIndex(vector<int>::iterator a, vector<int>::iterator b) {
            int n = distance(a, b);
            if (n < 3)
                return -1;

            auto m = a + n / 2;
            if (*m > *(m - 1) && *m > *(m + 1)) {
                return distance(a, m);
            }

            if (n == 3)
                return -1;

            int i = findPeakIndex(a, m + 1);
            if (i < 0) {
                i = findPeakIndex(m, b);
                if (i >= 0)
                    return distance(a, m) + i;
            }
            return i;
        }
    }  // namespace

    int findPeakElement(vector<int>& v) {
        if (v.size() < 20)
            return max_element(v.begin(), v.end()) - v.begin();
        return findPeakIndex(v.begin(), v.end());
    }

}  // namespace leet
