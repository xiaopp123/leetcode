#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/powx-n/description/
 * 快速幂，用二进制的方法求解
 * 对幂项用二进制表示，所以整体就变成了 a a^2 a^4 a^8 ...
 * 初始化base = a
 * 如果b个位为1，结果res * base
 * base = base * base
 * b右移一位
 */

class Solution {
    public:
    double myPow(double x, int n) {
        if (n >= 0) {
            return Pow(x, n);
        } else if (n != INT_MIN){
            return 1.0 / Pow(x, -n);
        } else {
            //如果是-2^31,转成正数后，就溢出了，这里稍微处理一下
            return 1.0 / Pow(x, -(n + 1)) / x;
        }
    }

    private:
    double Pow(double x, int n) {
        double res = 1.0;
        double base = x;
        while (n > 0) {
            if (n & 1) {
                res *= base;
            }
            base *= base;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    double x;
    int n;
    Solution* solution = new Solution();
    while (cin >> x >> n) {
        cout << solution->myPow(x, n) << endl;
    }

    return 0;
}
