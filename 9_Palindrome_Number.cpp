#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
    /**
     * https://leetcode.com/problems/palindrome-number/description/
     * 考虑特殊情况：
     * 负数返回false, 对于正数来说末位是0，但是这个数不是0也会返回false
     * 方法一：
     * 借助栈和队，对数进行按位比较
     * 方法二：
     * 对输入的数进行反转一半，然后进行比较
     * 核心问题就是如何找到一半，
     * 条件就是 x > reversedNum,
     * 如果是奇数，那么反转之后的会多一位，多出来的在个位，它并不影响回文，直接去掉，然后比较
     * 如果是偶数，对于回文来说，最后结果相等，如果不相等就是不回文
     *
     */
   // public:
   // bool isPalindrome(int x) {
   //     if (x < 0) {
   //         return false;
   //     }
   //     queue<int> q;
   //     stack<int> s;
   //     int mod;
   //     while (x) {
   //         mod = x % 10;
   //         x = x / 10;
   //         q.push(mod);
   //         s.push(mod);
   //     }

   //     while (!q.empty()) {
   //         int q_first = q.front();
   //         int s_first = s.top();
   //         q.pop();
   //         s.pop();
   //         if (q_first != s_first) {
   //             return false;
   //         }
   //     }

   //     return true;
   // }
    public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reversedNum = 0;
        while (x > reversedNum) {
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }

        return reversedNum == x || reversedNum / 10 == x;
    }

};
int main() {

    Solution* solution = new Solution();
    int x;
    while (cin >> x) {
        cout << solution->isPalindrome(x) << endl;
    }

    return 0;
}
