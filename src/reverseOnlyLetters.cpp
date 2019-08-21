/**

917. Reverse Only Letters

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and
all letters reverse their positions.


Example 1:

```
Input: "ab-cd"
Output: "dc-ba"
```

Example 2:

```
Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

Example 3:

```
Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```
 

Note:

 1. S.length <= 100
 2. 33 <= S[i].ASCIIcode <= 122 
 3. S doesn't contain \ or "


*/

#include "leet.h"

namespace leet {

    using namespace std;

    namespace {
        inline bool isLetter(char c) { return c >= 'a' || c <= 'Z' && c >= 'A'; }
    }  // namespace

    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (j > i) {
            if (isLetter(s[i]) && isLetter(s[j])) {
                swap(s[i], s[j]);
                ++i;
                --j;
            } else if (isLetter(s[i])) {
                --j;
            } else {
                ++i;
            }
        }
        return s;
    }

}  // namespace leet
