/**

1071. Greatest Common Divisor of Strings

For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.
 

Example 1:

```
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
```

Example 2:

```
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
```

Example 3:

```
Input: str1 = "LEET", str2 = "CODE"
Output: ""
```

Note:

 1. 1 <= str1.length <= 1000
 2. 1 <= str2.length <= 1000
 3. str1[i] and str2[i] are English uppercase letters.

*/

#include "leet.h"

#include <string_view>

namespace leet {

    using namespace std;

    namespace {
        inline bool stringDivides(string const& s1, string const& s2, string_view const& t) {
            // s1 has to be shorter than s2
            if (s1.size() % t.size() || s2.size() % t.size())
                return false;
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] != t[i % t.size()] || s2[i] != t[i % t.size()])
                    return false;
            }
            return true;
        }
    }  // namespace

    string gcdOfStrings(string str1, string str2) {
        if (str1.size() > str2.size())
            swap(str1, str2);

        for (int i = str1.size(); i > 0; --i) {
            if (stringDivides(str1, str2, string_view(str1.c_str(), i))) {
                return str1.substr(0, i);
            }
        }

        return "";
    }

}  // namespace leet
