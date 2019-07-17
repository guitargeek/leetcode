/**

1078. Occurences After Bigram

Given words first and second, consider occurrences in some text of the form "first second third", where second comes
immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

Example 1:

```
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
```

Example 2:

```
Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
```

Note:

  1. 1 <= text.length <= 1000
  2. text consists of space separated words, where each word consists of lowercase English letters.
  3. 1 <= first.length, second.length <= 10
  4. first and second consist of lowercase English letters.

*/

#include "leet.h"

#include <sstream>

namespace leet {

    using namespace std;

    vector<string> findOcurrences(string const& text, string const& first, string const& second) {
        vector<string> out;
        stringstream ss(text);
        string s0, s1, s2;
        while (getline(ss, s2, ' ')) {
            if (s0 == first && s1 == second)
                out.push_back(s2);
            s0.swap(s1);
            s1.swap(s2);
        }
        return out;
    }

}  // namespace leet
