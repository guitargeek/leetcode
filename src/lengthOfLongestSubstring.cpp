/**

3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

Example 2:

```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

Example 3:

```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```



*/

#include "leet.h"

#include <unordered_set>

namespace leet {

    using namespace std;

    int lengthOfLongestSubstring(string s) {
        auto n = s.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int l = 1;
        int lmax = 1;

        int i = 0;
        int j = 1;

        unordered_set<char> us{s[i]};

        while (j < n && n - i > lmax) {
            if (us.insert(s[j]).second) {
                lmax = max(lmax, ++l);
                ++j;
            } else {
                us.erase(s[i++]);
                us.insert(s[i]);
                if (i == j)
                    ++j;
                else
                    --l;
            }
        }

        return lmax;
    }

}  // namespace leet
