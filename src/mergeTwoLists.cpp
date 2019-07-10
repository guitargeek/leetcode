/**

21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of
the first two lists.

Example:

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

*/

#include "leet.h"

namespace leet {

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l0 = new ListNode{0};
        ListNode* l = l0;

        while (true) {
            if (l1 == NULL && l2 == NULL)
                return l0->next;

            if (l1 == NULL) {
                l->next = l2;
                return l0->next;
            } else if (l2 == NULL) {
                l->next = l1;
                return l0->next;
            } else if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }

        delete l0;
    }

}  // namespace leet
