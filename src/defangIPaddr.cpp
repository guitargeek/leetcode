/**

1108. Defanging an IP Address

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".


Example 1:

```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
```

Example 2:

```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
```

Constraints:

  * The given address is a valid IPv4 address.

*/

#include "leet.h"

namespace leet {

    using namespace std;

    string defangIPaddr(string address) {
        for (int pos = 0; (pos = address.find(".", pos)) != std::string::npos; pos += 3) {
            address.replace(pos, 1, "[.]");
        }
        return address;
    }

}  // namespace leet
