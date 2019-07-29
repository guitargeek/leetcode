/**

1115. Print FooBar Alternately

Suppose you are given the following code:

```
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
```

The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call
bar(). Modify the given program to output "foobar" n times.
 

Example 1:

```
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
```

Example 2:

```
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
```

*/

#include "leet.h"

#include <mutex>
#include <functional>

namespace leet {

    using namespace std;

    class FooBar {
      public:
        FooBar(int n) {
            this->n = n;
            mutex2.lock();
        }

        void foo(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                mutex1.lock();

                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();

                mutex2.unlock();
            }
        }

        void bar(function<void()> printBar) {
            for (int i = 0; i < n; i++) {
                mutex2.lock();

                // printBar() outputs "bar". Do not change or remove this line.
                printBar();

                mutex1.unlock();
            }
        }

      private:
        int n;

        mutex mutex1;
        mutex mutex2;
    };

}  // namespace leet
