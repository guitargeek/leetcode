/**

155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    * push(x) -- Push element x onto stack.
    * pop() -- Removes the element on top of the stack.
    * top() -- Get the top element.
    * getMin() -- Retrieve the minimum element in the stack.

Example:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

*/

#include "leet.h"

#include <stack>

namespace leet {

  using namespace std;

  class MinStack {
  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
      if (stack_.empty()) {
        minst_.push(x);
      } else {
        minst_.push(min(minst_.top(), x));
      }
      stack_.push(x);
    }

    void pop() {
      stack_.pop();
      minst_.pop();
    }

    int top() { return stack_.top(); }

    int getMin() { return minst_.top(); }

  private:
    stack<int> stack_;
    stack<int> minst_;
  };

  /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

}  // namespace leet
