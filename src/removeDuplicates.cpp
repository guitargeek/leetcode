/**

1047. Remove All Adjacent Duplicates In String

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and
removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

```
Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible
move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is
"ca".
```

Note:

  1. 1 <= S.length <= 20000
  2. S consists only of English lowercase letters.

*/

#include "leet.h"

#include <list>

namespace leet {

    using namespace std;

    string removeDuplicates(string str) {
        list<char> l(str.begin(), str.end());
        l.push_front('0');

        auto i = l.begin();
        auto j = next(l.begin());
        int k = 0;
        for (; j != l.end(); ++i, ++j) {
            while (*i == *j) {
                j = l.erase(j);
                i = --l.erase(i);
            }
        }

        return string(next(l.begin()), l.end());
    }

}  // namespace leet
