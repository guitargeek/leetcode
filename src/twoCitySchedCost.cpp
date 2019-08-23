/**

1229. Two City Scheduling

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0],
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.


Example 1:

```
Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
```

Note:

 1. 1 <= costs.length <= 100
 2. It is guaranteed that costs.length is even.
 3. 1 <= costs[i][0], costs[i][1] <= 1000

*/

#include "leet.h"

#include <algorithm>

namespace leet {

    using namespace std;

    namespace {
        struct CostInfo {
            int cost : 11;
            int diff : 11;
            bool dest : 1;
        };

    }  // namespace

    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<CostInfo> v(costs.size());
        for (int i = 0; i < costs.size() / 2; ++i) {
            v[i] = {costs[i][0], costs[i][1] - costs[i][0], 0};
        }
        for (int i = costs.size() / 2; i < costs.size(); ++i) {
            v[i] = {costs[i][1], costs[i][0] - costs[i][1], 1};
        }
        sort(v.begin(), v.end(), [](auto const& x1, auto const& x2) { return abs(x1.diff) > abs(x2.diff); });

        for (int j = 0; j < v.size() - 1; ++j) {
            if (v[j].diff > 0)
                continue;
            for (int i = j + 1; i < v.size(); ++i) {
                if (v[i].dest + v[j].dest == 1 && v[i].diff + v[j].diff < 0) {
                    v[i].cost = v[i].cost + v[i].diff;
                    v[j].cost = v[j].cost + v[j].diff;
                    v[i].diff = -v[i].diff;
                    v[j].diff = -v[j].diff;
                    bool dest = v[i].dest;
                    v[i].dest = v[j].dest;
                    v[j].dest = dest;
                }
            }
        }

        int cost = 0;
        for (int i = 0; i < v.size(); ++i) {
            cost += v[i].cost;
        }

        return cost;
    }

}  // namespace leet
