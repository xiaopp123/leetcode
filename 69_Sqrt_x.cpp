#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
//http://www.cnblogs.com/grandyang/p/6854825.html

class Solution {
    public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int l = 1, r = x;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l - 1;
    }
};
int main() {
    Solution* solution = new Solution();
    int x;
    while (cin >> x) {
        cout << solution->mySqrt(x) << endl;
    }
}
