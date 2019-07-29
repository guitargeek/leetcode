/**

1128. Number of Equivalent Domino Pairs

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either
(a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].


Example 1:

```
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
```

Constraints:

 1. 1 <= dominoes.length <= 40000
 2. 1 <= dominoes[i][j] <= 9

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> counter(81, 0);
        for (auto& d : dominoes) {
            sort(d.begin(), d.end());
            counter[(d[0] - 1) * 9 + d[1] - 1]++;
        }
        int n = 0;
        for (int x : counter) {
            n += x * (x - 1) / 2;
        }
        return n;
    }

}  // namespace leet
