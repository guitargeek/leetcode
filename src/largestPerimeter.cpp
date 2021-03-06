/**

976. Largest Perimeter Triangle

Given an array A of positive lengths, return the largest perimeter of a
triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.


Example 1:

```
Input: [2,1,2]
Output: 5
```

Example 2:

```
Input: [1,2,1]
Output: 0
```

Example 3:

```
Input: [3,2,3,4]
Output: 10
```

Example 4:

```
Input: [3,6,2,3]
Output: 8
```

Note:

 1. 3 <= A.length <= 10000
 2. 1 <= A[i] <= 10^6

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    int largestPerimeter(vector<int>& a) {
        sort(a.begin(), a.end(), greater<int>());

        for (int i = 0; i < a.size() - 2; ++i) {
            if (a[i + 0] < a[i + 1] + a[i + 2]) {
                return a[i + 0] + a[i + 1] + a[i + 2];
            }
        }
        return 0;
    }

}  // namespace leet
