/**

20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

```
Input: "()"
Output: true
```

Example 2:

```
Input: "()[]{}"
Output: true
```

Example 3:

```
Input: "(]"
Output: false
```

Example 4:

```
Input: "([)]"
Output: false
```

Example 5:

```
Input: "{[]}"
Output: true
```

*/

#include "leet.h"

#include <stack>

namespace leet {

  using namespace std;

    namespace {
        constexpr pair<char,char> b1{'(', ')'};
constexpr pair<char,char> b2{'{', '}'};
constexpr pair<char,char> b3{'[', ']'};

constexpr pair<char,char> pairs [3] = {b1, b2, b3};
    }

    bool isValid(string const& s) {
        
        if(s.size() % 2 == 1) return false;

        stack<char> brackets;
        brackets.push('s');
        
        for(auto const& c : s) {
            for(auto const& p : pairs) {
                if(c == p.first) {
                    brackets.push(c);
                } else if(c == p.second) {
                    if(brackets.top() == p.first) {
                        brackets.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return brackets.size() == 1;
    }

}  // namespace leet
