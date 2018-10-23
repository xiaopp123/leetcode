#include <cstdio>
#include <limits.h>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
    /**
     * https://leetcode.com/problems/string-to-integer-atoi/description/
     * 保留一下我这肮脏的代码
     *
    public:
    int myAtoi(string str) {
        int len = str.length();
        int res = 0;
        int index = 0;
        int flag = 1;
        while (index < len) {
            while (index < len && str[index] == ' ') {
                index++;
            }
            if (index >= len) {
                break;
            }
            if (str[index] == '-') {
                flag = 0;
            }
            if (str[index] < '0' || str[index] > '9') {
                if (res == 0) {
                    index++;
                    continue;
                } else {
                    res = 0;
                    break;
                }
            }
            if (str[index] > '0' && str[index] < '9') {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[index] - '0' > 7)) {
                    res = INT_MAX;
                    break;
                }
                res = res * 10 + str[index] - '0';
            }
            index++;
        }

        return res;
    }
    */
    public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int len = str.length();
        int index = 0;

        while (index < len && str[index] == ' ') {
            index++;
        }
        if (str[index] == '-' || str[index] == '+') {
            sign = str[index] == '+' ? 1 : -1;
            index++;
        }
        while (index < len && str[index] >= '0' && str[index] <= '9') {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[index] > '7')) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            res = res * 10 + str[index++] - '0';
        }

        return res * sign;
    }

};
int main() {
    Solution* solution = new Solution();
    string str;
    while (cin >> str) {
         cout << solution->myAtoi(str) << endl;
    }


    return 0;
}
