/**

1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't
appear in arr2 should be placed at the end of arr1 in ascending order.


Example 1:

```
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

Constraints:

  * arr1.length, arr2.length <= 1000
  * 0 <= arr1[i], arr2[i] <= 1000
  * Each arr2[i] is distinct.
  * Each arr2[i] is in arr1.

*/

#include "leet.h"

#include <algorithm>
#include <unordered_map>

namespace leet {

    using namespace std;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> counter;

        for (int x : arr1) {
            ++counter[x];
        }

        int i = 0;
        for (int x : arr2) {
            for (int n = i; i - n < counter[x]; ++i) {
                arr1[i] = x;
            }
            counter.erase(x);
        }

        auto middle = arr1.begin() + i;

        for (auto const& c : counter) {
            for (int n = i; i - n < c.second; ++i) {
                arr1[i] = c.first;
            }
        }

        sort(middle, arr1.end());

        return arr1;
    }

}  // namespace leet
