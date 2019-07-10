/**

13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is
simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

*/

#include "leet.h"

namespace leet {

    using namespace std;

    int romanToInt(string s) {
        int n = 0;
        char p = '0';
        for (auto c : s) {
            if (c == 'I') {
                n += 1;
            } else if (c == 'V') {
                if (p == 'I') {
                    n += 3;
                } else {
                    n += 5;
                }
            } else if (c == 'X') {
                if (p == 'I') {
                    n += 8;
                } else {
                    n += 10;
                }
            } else if (c == 'L') {
                if (p == 'X') {
                    n += 30;
                } else {
                    n += 50;
                }
            } else if (c == 'C') {
                if (p == 'X') {
                    n += 80;
                } else {
                    n += 100;
                }
            } else if (c == 'D') {
                if (p == 'C') {
                    n += 300;
                } else {
                    n += 500;
                }
            } else if (c == 'M') {
                if (p == 'C') {
                    n += 800;
                } else {
                    n += 1000;
                }
            }
            p = c;
        }
        return n;
    }

}  // namespace leet
