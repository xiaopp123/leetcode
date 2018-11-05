#include <cstdio>
#include <limits.h>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

/**
 * 1、利用二进制进行分块
 * 2、同号或者异号可以用异或进行判断
 */

class Solution {
    public:
    int divide(int dividend, int divisor) {
        long long a = fabs(dividend);
        long long b = fabs(divisor);
        long long ret = 0;
        while (a >= b) {
            long long c = b;
            for (int i = 0; a >= c; i++, c <<= 1) {
                a -= c;
                ret += (1 << i);
            }
        }

        if ((dividend ^ divisor) >> 31) {
            return -1 * ret < INT_MIN ? INT_MIN : -1 * ret;
        }

        return ret > INT_MAX ? INT_MAX : ret;
    }
};

int main() {
    Solution* solution = new Solution();
    int dividend, divisor;

    while (cin >> dividend >> divisor) {
        cout << (((dividend ^ divisor) >> 31)) << endl;
        cout << solution->divide(dividend, divisor);
    }

    return 0;
}
