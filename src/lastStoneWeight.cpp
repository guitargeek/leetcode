/**

1046. Last Stone Weight

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.

At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)


Example 1:

```
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
```


Note:

    1 <= stones.length <= 30
    1 <= stones[i] <= 1000

*/

#include "leet.h"

#include <algorithm>
#include <functional>

namespace leet {

  using namespace std;

  int lastStoneWeight(vector<int>& stones) {
    // sort stones by decreasing weight
    sort(stones.begin(), stones.end(), greater<int>());

    while (stones.size() > 1) {
      // compute weight of resulting stone and put it as the second element
      stones[1] = stones[0] - stones[1];
      stones[0] = 0;
      if (stones[1] > 0) {
        // move all the remaining stones one index to the front and remove the tail to get rid of the zero weight entry
        stones.erase(remove(stones.begin(), stones.end(), 0), stones.end());
        // insert the resulting stone at the right place to the stones remain sorted, no memory allocation required as
        // stones.capacity() >= stones.size() + 1 as we erased the last element before
        stones.insert(upper_bound(stones.begin() + 1, stones.end(), stones[0], greater<int>()), stones[0]);
        // now we can erase the first element which we have inserted somewhere else
        stones.erase(stones.begin(), stones.begin() + 1);
      } else {
        // if the resulting stone has also weight zeros, we can just red rid of the two elements
        stones.erase(stones.begin(), stones.begin() + 2);
      }
    }

    return stones[0];
  }

}  // namespace leet
