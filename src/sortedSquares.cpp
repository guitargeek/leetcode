/**

977. Squares of a Sorted Array

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in
sorted non-decreasing order.

Example 1:

```
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```

Example 2:

```
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

Note:

    1. `1 <= A.length <= 10000`
    2. `-10000 <= A[i] <= 10000`
    3. A is sorted in non-decreasing order.

*/

#include "leet.h"

#include <algorithm>

namespace leet {

  using namespace std;

  vector<int> sortedSquares(vector<int>& A) {
    vector<int> B(A.size());
    int i = 0;
    for (auto const& x : A) {
      B[i] = x * x;
      ++i;
    }
    sort(B.begin(), B.end());
    return B;
  }

}  // namespace leet
