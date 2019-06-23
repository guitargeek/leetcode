/**

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

```
Input: ["flower","flow","flight"]
Output: "fl"
```

Example 2:

```
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

Note:

All given inputs are in lowercase letters a-z.

*/

#include "leet.h"

#include <stdexcept>

namespace leet {

  using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        string prefix{};
        int i = 0;
        while(true) {
            try {
                auto c = strs.at(0).at(i);
                for(auto const& str : strs) {
                    auto d = str.at(i);
                    if(c != d) return prefix;;
                }
                prefix += c;
            } catch(const std::out_of_range&) {
                    break;
            }
            ++i;
        }
        
        return prefix;
    }

}  // namespace leet
