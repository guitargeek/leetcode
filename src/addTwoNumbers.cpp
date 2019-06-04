/**

2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

*/

#include "leet.h"

namespace leet {

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1begin = l1;
    ListNode* l2begin = l2;

    ListNode* l;

    while (true) {
      int x = 0;
      if (l1 == NULL) {
        l = l2begin;
        break;
      } else
        x += l1->val;
      if (l2 == NULL) {
        l = l1begin;
        break;
      } else
        x += l2->val;
      if (l1 != NULL)
        l1->val = x;
      if (l2 != NULL)
        l2->val = x;
      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode* out = l;

    while (l) {
      if (l->val > 9) {
        l->val = l->val % 10;
        if (l->next) {
          l->next->val += 1;
        } else {
          l->next = new ListNode(1);
        }
      }
      l = l->next;
    }
    return out;
  }

}  // namespace leet
