/**

234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:

```
Input: 1->2
Output: false
```

Example 2:

```
Input: 1->2->2->1
Output: true
```

Follow up:
Could you do it in O(n) time and O(1) space?

*/

#include "leet.h"

namespace leet {

    using namespace std;

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        vector<int> values;
        values.push_back(head->val);
        while (head->next) {
            head = head->next;
            values.push_back(head->val);
        }
        int i = 0;
        int j = values.size() - 1;
        while (j > i) {
            if (values[i] != values[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }

}  // namespace leet
