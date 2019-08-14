/**

338. Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in
their binary representation and return them as an array.

Example 1:

```
Input: 2
Output: [0,1,1]
```

Example 2:

```
Input: 5
Output: [0,1,1,2,1,2]
```

Follow up:

  * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
  * Space complexity should be O(n).
  * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/

#include "leet.h"

namespace leet {

    using namespace std;

    vector<int> countBits(int num) {
        if (num == 0)
            return {0};
        if (num == 1)
            return {0, 1};

        vector<int> v(num + 1);
        v[0] = 0;
        v[1] = 1;

        int i = 2;
        while (i <= num) {
            for (int j = i; j < 2 * i && j < num + 1; ++j) {
                v[j] = v[j - i] + 1;
            }
            i *= 2;
        }
        return v;
    }

}  // namespace leet
