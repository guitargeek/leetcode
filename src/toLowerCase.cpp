/**

709. To Lower Case

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.


Example 1:

```
Input: "Hello"
Output: "hello"
```

Example 2:

```
Input: "here"
Output: "here"
```

Example 3:

```
Input: "LOVELY"
Output: "lovely"
```

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    string toLowerCase(string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

}  // namespace leet
