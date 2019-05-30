/**

206. Reverse Linked List

Reverse a singly linked list.

Example:

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include "leet.h"

namespace leet {

  using namespace std;

  ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
      auto next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }

  /*
     * This is the recursive solution, which is slower however so we don't use it.
     *
     *ListNode* reverseList(ListNode* head, ListNode* tail=NULL) {
     *    if(head == NULL) return head;
     *    auto next = head->next;
     *    head->next = tail;
     *    if(next == NULL) return head;
     *    return reverseList(next, head);
     *}
     */

}  // namespace leet
