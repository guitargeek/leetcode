/**

693. Binary Number with Alternating Bits

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:

```
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
```

Example 2:

```
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
```

Example 3:

```
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
```

Example 4:

```
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
```

*/

#include "leet.h"

namespace leet {

    namespace {
        constexpr int a = 0b00101010'10101010'10101010'10101010;
        constexpr int b = 0b01010101'01010101'01010101'01010101;
    }  // namespace

    bool hasAlternatingBits(int n) {
        if (n & 0b01000000'00000000'00000000'00000000)
            return n == b;

        return !((n ^ (n % 2 ? b : a)) & n) && !(((n ^ (n << 2)) & n) - 2 + n % 2);
    }

}  // namespace leet
