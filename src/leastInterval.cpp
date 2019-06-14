/**

621. Task Scheduler

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each
interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n
intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example:

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
```

Note:

    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].

*/

#include "leet.h"

#include <algorithm>

namespace leet {

  using namespace std;

  int leastInterval(vector<char>& tasks, int n) {
    vector<int> counts(26, 0);
    for (char task : tasks) {
      ++counts[task - 'A'];
    }
    sort(counts.begin(), counts.end());
    int i = 0;
    // How many times does the maximum occur?
    while (i <= 25 && counts[25 - i] == counts[25])
      ++i;
    // How  many steps you need to execute only the tasks which occured the most?
    // if there are other tasks which have to be executed just as often,
    // increase sequence length by one.
    // The remaining tasks get used up to fill the idle cycles,
    // and if there are too many we more cycles have to be added in which case
    // the answer will just be tasts.size()
    return max(int(tasks.size()), (counts[25] - 1) * n + counts[25] + i - 1);
  }

}  // namespace leet
