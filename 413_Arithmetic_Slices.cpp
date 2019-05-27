#include "heads.h"
using namespace std;

/*
 * 长度为n的等差序列包含 (n - 1) * (n - 2) * 0.5个不小于3的

class Solution {
    public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = 2;
        int res = 0;
        for (int i = 2; i < (int)A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                len++;
            } else {
                if (len > 2) {
                    res += (len - 1) * (len - 2) * 0.5;
                }
                len = 2;
            }
        }
        if (len > 2) {
            res += (len - 1) * (len - 2) * 0.5;
        }

        return res;
    }
};
 */

/*
class Solution {
    public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        vector<int> dp(A.size(), 0);
        for (int i = 2; i < (int)A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            res += dp[i];
        }
        return res;
    }
};
*/

class Solution {
    public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int cur = 0;
        for (int i = 2; i < (int)A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                cur += 1;
                res += cur;
            } else {
                cur = 0;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
