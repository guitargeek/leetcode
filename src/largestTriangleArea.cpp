/**

812. Largest Triangle Area

You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the
points.

```
Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.
```

Notes:

  * 3 <= points.length <= 50.
  * No points will be duplicated.
  *  -50 <= points[i][j] <= 50.
  * Answers within 10^-6 of the true value will be accepted as correct.


*/

#include "leet.h"

#include <cmath>

namespace leet {

    using namespace std;

    double largestTriangleArea(vector<vector<int>>& p) {
        double a2 = 0.0;

        for (int i = 0; i < p.size() - 2; ++i) {
            for (int j = i + 1; j < p.size() - 1; ++j) {
                int dx = 0;
                int dy = 1;
                if (p[j][dx] - p[i][dx] == 0) {
                    swap(dx, dy);
                }
                double s2 =
                    (p[j][dy] - p[i][dy]) * (p[j][dy] - p[i][dy]) + (p[j][dx] - p[i][dx]) * (p[j][dx] - p[i][dx]);
                double a = (1.0 * p[j][dy] - p[i][dy]) / (p[j][dx] - p[i][dx]);
                double c = p[i][dy] - a * p[i][dx];
                for (int k = j + 1; k < p.size(); ++k) {
                    double a0 = p[k][dx];
                    double b0 = p[k][dy];
                    double num = a * a0 - b0 + c;
                    double d2 = num * num / (a * a + 1);
                    a2 = max(a2, s2 * d2);
                }
            }
        }
        return sqrt(a2) / 2.;
    }

}  // namespace leet
