/**

128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

```
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        sort(nums.begin(), nums.end());
        int longest = 1;
        int len = 1;
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            if (*it - 1 == *(it - 1)) {
                ++len;
            } else if (*it == *(it - 1)) {
                continue;
            } else {
                longest = max(longest, len);
                len = 1;
            }
        }
        return max(longest, len);
    }

}  // namespace leet
