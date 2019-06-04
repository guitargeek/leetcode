/**

200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and
is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

```
Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3
```

*/

#include "leet.h"

namespace leet {

  using namespace std;

  namespace {

    bool mark(int x, int y, vector<vector<char>>& grid) {
      if (x >= grid.size() || x < 0)
        return false;
      if (y >= grid[0].size() || y < 0)
        return false;
      if (grid[x][y] != '1')
        return false;

      grid[x][y] = 'm';

      mark(x + 1, y, grid);
      mark(x - 1, y, grid);
      mark(x, y + 1, grid);
      mark(x, y - 1, grid);

      return true;
    }

  }  // namespace

  int numIslands(vector<vector<char>>& grid) {
    int islandCount = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (mark(i, j, grid))
          islandCount++;
      }
    }
    return islandCount;
  }

}  // namespace leet