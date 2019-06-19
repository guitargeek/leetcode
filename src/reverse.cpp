/**

7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

```
Input: 123
Output: 321
```

Example 2:

```
Input: -123
Output: -321
```

Example 3:

```
Input: 120
Output: 21
```

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,
231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

#include "leet.h"

#include <cmath>

namespace leet {

  using namespace std;

  int reverse(int x) {
    if (x == 0)
      return 0;
    if (x == -2147483648)
      return 0;
    if (x < 0)
      return -reverse(-x);

    int digits = log10(x);
    int result = 0;
    int d = 0;
    int f = 1;
    int e = pow(10, digits);

    while (true) {
      d = x / e;
      if (long(d) * f + result > numeric_limits<int>::max())
        return 0;
      result += d * f;
      x -= d * e;
      e /= 10;
      if (e == 0)
        return result;
      f *= 10;
    }
  }

}  // namespace leet
