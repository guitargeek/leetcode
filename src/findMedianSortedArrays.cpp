/**

4. Median of Two Sorted Arrays

There are two sorted arrays `nums1` and `nums2` of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume `nums1` and `nums2` cannot be both empty.

Example 1:

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

Example 2:

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

*/

#include "leet.h"

#include <iostream>

namespace leet {

    namespace {
        using iter = std::vector<int>::const_iterator;

        inline double median(iter a, iter b, int n) {
            if (n % 2 == 1)
                return a[n / 2];
            return (a[n / 2] + a[n / 2 - 1]) / 2.;
        }

        inline double medianWithExtraNumber(iter a, iter b, int x, int n) {
            if (b - a == 1)
                return (a[0] + x) / 2.;
            if (n % 2 == 0) {
                auto m = a[n / 2];
                if (x >= m)
                    return m;
                return std::max(a[n / 2 - 1], x);
            } else {
                auto m = a[n / 2];
                if (x >= m)
                    return (m + std::min(x, a[n / 2 + 1])) / 2.;
                return (m + std::max(x, a[n / 2 - 1])) / 2.;
            }
        }

        void print(iter a, iter b) {
            // for debugging
            std::cout << "[ ";
            for (auto i = a; i != b; ++i) {
                std::cout << *i << " ";
            }
            std::cout << "]" << std::endl;
        }
    }  // namespace

    double findMedianSortedArrays(std::vector<int> const& nums1, std::vector<int> const& nums2) {
        auto a1 = nums1.begin();
        auto b1 = nums1.end();

        auto a2 = nums2.begin();
        auto b2 = nums2.end();

        while (true) {
            auto n1 = b1 - a1;
            auto n2 = b2 - a2;

            if (n1 == 0)
                return median(a2, b2, n2);
            if (n2 == 0)
                return median(a1, b1, n1);

            if (n1 == 1)
                return medianWithExtraNumber(a2, b2, a1[0], n2);
            if (n2 == 1)
                return medianWithExtraNumber(a1, b1, a2[0], n1);

            auto m1 = median(a1, b1, n1);
            auto m2 = median(a2, b2, n2);

            if (m1 == m2)
                return m1;

            int r = std::min(n1, n2) / 2;
            if (m1 < m2) {
                if (*(b2 - r) < a1[n1 / 2])
                    b1 -= r;
                else
                    b2 -= r;
                if (*(a1 + r - 1) > a2[n2 / 2 - 1])
                    a2 += r;
                else
                    a1 += r;
            } else {
                if (*(b1 - r) < a2[n2 / 2])
                    b2 -= r;
                else
                    b1 -= r;
                if (*(a2 + r - 1) > a1[n1 / 2 - 1])
                    a1 += r;
                else
                    a2 += r;
            }
        }
    }

}  // namespace leet
