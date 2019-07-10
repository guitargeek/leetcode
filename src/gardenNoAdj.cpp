/**

1042. Flower Planting With No Adjacent

You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have
different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The
flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

 

Example 1:

```
Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
```

Example 2:

```
Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
```

Example 3:

```
Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]
```

*/

#include "leet.h"

#include <algorithm>
#include <numeric>

namespace leet {

    using namespace std;

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> flowers(N, 1);

        if (N <= 4) {
            iota(flowers.begin(), flowers.end(), 1);
            return flowers;
        }

        sort(paths.begin(), paths.end(), [](auto& p1, auto& p2) {
            if (p1[0] == p2[0])
                return p1[1] < p2[1];
            return p1[0] < p2[0];
        });

        bool run = true;
        while (run) {
            run = false;

            for (auto const& path : paths) {
                if (flowers[path[0] - 1] == flowers[path[1] - 1]) {
                    flowers[path[1] - 1] = (flowers[path[1] - 1] % 4) + 1;
                    run = true;
                }
            }
        }

        return flowers;
    }

}  // namespace leet
