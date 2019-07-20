#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};

/**
 * https://leetcode.com/problems/counting-bits/
 * 统计[0, num]各个数二进制中1的个数
 * 直观做法 n(sizeof(n))
 * 但上面做法没有考虑之前的计算可以对当前的计算有帮助
 * 以求 6 为例，6 = 110，前两位组成的是4 = 11，所以只需判断最后一位即可
 * 故 res[i] = res[i >> 1] + (i & 1)
 */
class Solution {
    public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        /*
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 1) {
                res[i] = res[i >> 1] + 1;
            } else {
                res[i] = res[i >> 1];
            }
        }
        */
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

int main() {

    return 0;
}
