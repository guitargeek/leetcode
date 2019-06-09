/**

70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

```
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

Example 2:

```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

*/

#include "leet.h"

namespace leet {

  int climbStairs(int n) {
    int a = 1;
    int b = 1;
    int c;

    for (int i = 0; i < n - 1; ++i) {
      c = a;
      a = a + b;
      b = c;
    }

    return a;
  }

}  // namespace leet
