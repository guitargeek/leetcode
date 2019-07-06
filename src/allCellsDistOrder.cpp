/**

1030. Matrix Cells in Distance Order

We are given a matrix with R rows and C columns has cells with integer coordinates (r, c),
where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to
largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1
- c2|.  (You may return the answer in any order that satisfies this condition.)

Example 1:

```
Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]
```

Example 2:

```
Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
```

Example 3:

```
Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
```

Note:

    1 <= R <= 100
    1 <= C <= 100
    0 <= r0 < R
    0 <= c0 < C

*/

#include "leet.h"

#include <algorithm>
#include <numeric>

namespace leet {

  using namespace std;

  namespace {

    template <class I1, class I2>
    void sort_by_key(I1 keys_begin, I1 keys_end, I2 data_begin, I2 data_end) {
      size_t size = keys_end - keys_begin;
      std::vector<size_t> p(size, 0);
      std::vector<size_t> rp(size);
      std::vector<bool> sorted(size, false);
      size_t i = 0;

      // Sort
      std::iota(p.begin(), p.end(), 0);
      std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return *(keys_begin + i) < *(keys_begin + j); });

      // ----------- Apply permutation in-place ---------- //

      // Get reverse permutation item>position
      for (i = 0; i < size; ++i) {
        rp[p[i]] = i;
      }

      i = 0;
      typename I1::value_type savedKey;
      typename I2::value_type savedData;
      while (i < size) {
        size_t pos = i;
        // Save This element;
        if (!sorted[pos]) {
          savedKey = *(keys_begin + p[pos]);
          savedData = *(data_begin + p[pos]);
        }
        while (!sorted[pos]) {
          // Hold item to be replaced
          typename I1::value_type heldKey = *(keys_begin + pos);
          typename I2::value_type heldData = *(data_begin + pos);
          // Save where it should go
          size_t heldPos = rp[pos];

          // Replace
          *(keys_begin + pos) = savedKey;
          *(data_begin + pos) = savedData;

          // Get last item to be the pivot
          savedKey = heldKey;
          savedData = heldData;

          // Mark this item as sorted
          sorted[pos] = true;

          // Go to the held item proper location
          pos = heldPos;
        }
        ++i;
      }
    }

    template <class RandomAccessIterator, class Extractor, class Compare>
    void precomputed_value_sort(RandomAccessIterator begin,
                                RandomAccessIterator end,
                                const Extractor& extr,
                                const Compare& comp) {
      using Value = typename std::iterator_traits<RandomAccessIterator>::value_type;
      using Scalar = decltype(extr(*begin));

      std::vector<Scalar> keys;
      keys.reserve(end - begin);
      for (auto i = begin; i != end; i++)
        keys.emplace_back(extr(*i));
      sort_by_key(keys.begin(), keys.end(), begin, end);
    }

    template <class RandomAccessIterator, class Extractor>
    void precomputed_value_sort(RandomAccessIterator begin, RandomAccessIterator end, const Extractor& extr) {
      using Scalar = decltype(extr(*begin));
      precomputed_value_sort(begin, end, extr, std::less<Scalar>());
    }

  }  // namespace

  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> p;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        p.push_back({r, c});
      }
    }
    precomputed_value_sort(
        p.begin(),
        p.end(),
        [&](auto const& p1) { return abs(p1[0] - r0) + abs(p1[1] - c0); },
        [](auto const& d1, auto const& d2) { return d1 < d2; });
    return p;
  }

}  // namespace leet
