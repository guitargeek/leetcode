/**

771. Jewels and Stones

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each
character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a"
is considered a different type of stone from "A".

Example 1:

```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

Example 2:

```
Input: J = "z", S = "ZZ"
Output: 0
```

Note:

  * S and J will consist of letters and have length at most 50.
  * The characters in J are distinct.

*/

#include "leet.h"

#include <unordered_set>

namespace leet {

    using namespace std;

    int numJewelsInStones(string J, string S) {
        int counter = 0;

        unordered_set<char> jewels;

        for (auto const& c : J) {
            jewels.insert(c);
        }

        for (auto const& c : S) {
            if (jewels.find(c) != jewels.end())
                ++counter;
        }

        return counter;
    }

}  // namespace leet
