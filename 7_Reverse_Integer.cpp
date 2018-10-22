#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;


class Solution {
    public:
    int reverse(int x) {
        /**
         * 核心是如何判断溢出
         * 以正数为例
         * 当res > INT_MAX / 10时,必然溢出
         * 当res == INT_MAX / 10时，如果mod > 7溢出
         * 对于负数来说也是一样
         */
        int maxInt = 2147483647;
        int minInt = -2147483648;
        int res = 0;
        int mod;
        while (x != 0) {
            mod = x % 10;
            x = x / 10;
            if (res > maxInt / 10 || (res == maxInt / 10 && mod > 7)) {
                return 0;
            }
            if (res < minInt / 10 || (res == minInt / 10 && mod < -8)) {
                return 0;
            }
            res = res * 10 + mod;
        }

        return res;
    }
};

int main() {
    Solution* solution = new Solution();
    int x;
    while (cin >> x) {
        cout << solution->reverse(x) << endl;
    }

    return 0;
}
