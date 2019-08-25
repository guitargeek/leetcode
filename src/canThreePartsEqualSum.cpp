/**

1013. Partition Array Into Three Parts With Equal Sum

Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with
equal sums.

Formally, we can partition the array if we can find indexes i+1 < j
with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

 
Example 1:

```
Input: [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
```

Example 2:

```
Input: [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
```

Example 3:

```
Input: [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
```

Note:

 1. 3 <= A.length <= 50000
 2. -10000 <= A[i] <= 10000

*/

#include "leet.h"

#include <numeric>

namespace leet {

    using namespace std;

    bool canThreePartsEqualSum(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 3)
            return false;
        int n = 0;
        for (int i = 0; i < a.size(); ++i) {
            n += a[i];
            if (n == sum / 3)
                n = 0;
        }
        return !n;
    }

}  // namespace leet
