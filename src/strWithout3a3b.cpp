/**

984. String Without AAA or BBB

Given two integers A and B, return any string S such that:

 *  S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
 *  The substring 'aaa' does not occur in S;
 *  The substring 'bbb' does not occur in S.

 

Example 1:

```
Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
```

Example 2:

```
Input: A = 4, B = 1
Output: "aabaa"
```
 

Note:

 *  0 <= A <= 100
 *  0 <= B <= 100
 *  It is guaranteed such an S exists for the given A and B.

*/

#include "leet.h"

namespace leet {

    std::string strWithout3a3b(int A, int B) {
        std::string S = "";
        if (A > B) {
            for (int i = 0; i < A - B; ++i) {
                S += "aab";
            }
            for (int i = 0; i < B - (A - B); ++i) {
                S += "ab";
            }
        } else if (B > A) {
            for (int i = 0; i < B - A; ++i) {
                S += "bba";
            }
            for (int i = 0; i < A - (B - A); ++i) {
                S += "ba";
            }
        } else {
            for (int i = 0; i < A; ++i) {
                S += "ab";
            }
        }
        return S.substr(0, A + B);
    }

}  // namespace leet
