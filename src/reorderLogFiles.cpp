/**

937. Reorder Log Files

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

  * Each word after the identifier will consist only of lowercase letters, or;
  * Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one
word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered
lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their
original order.

Return the final order of the logs.

 

Example 1:

```
Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```

Note:

 1. 0 <= logs.length <= 100
 2. 3 <= logs[i].length <= 100
 3. logs[i] is guaranteed to have an identifier, and a word after the identifier.

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    vector<string> reorderLogFiles(vector<string>& logs) {
        auto middle = stable_partition(logs.begin(), logs.end(), [](auto const& log) { return log.back() > 64; });
        sort(logs.begin(), middle, [](auto const& log1, auto const& log2) {
            auto f1 = log1.find(' ') + 1;
            auto f2 = log2.find(' ') + 1;
            std::string_view v1{log1.c_str() + f1, log1.size() - f1};
            std::string_view v2{log2.c_str() + f2, log2.size() - f2};

            if (v1 == v2)
                return log1 < log2;
            return v1 < v2;
        });
        return logs;
    }

}  // namespace leet
