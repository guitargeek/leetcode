/**

784. Letter Case Permutation

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create.

```
Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
```

Note:

  * S will be a string with length between 1 and 12.
  * S will consist only of letters or digits.


*/

#include "leet.h"

namespace leet {

    using namespace std;
    namespace {

        inline pair<int, int> findLetter(string const& s, int pos = 0) {
            for (int i = pos; i < s.size(); ++i) {
                char c = s[i];
                int d = 0;
                if (c >= 65 && c <= 90) {
                    return {i, 1};
                } else if (c >= 97 && c <= 122) {
                    return {i, -1};
                } else {
                    continue;
                }
            }
            return {s.size(), 0};
        }

        void recourse(string const& s, int m, vector<string>& v) {
            auto found = findLetter(s, m);

            if (found.first == s.size())
                return;

            int n1 = v.size();
            recourse(s, found.first + 1, v);
            int n2 = v.size();
            for (int j = n1; j < n2; ++j) {
                v.push_back(v[j]);
                v.back()[found.first] += found.second * 32;
            }
            v.push_back(s);
            v.back()[found.first] += found.second * 32;
        }
    }  // namespace

    vector<string> letterCasePermutation(string const& s) {
        vector<string> out{s};
        recourse(s, 0, out);
        return out;
    }

}  // namespace leet
