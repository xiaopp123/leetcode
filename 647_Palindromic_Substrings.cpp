#include "heads.h"

using namespace std;

class Solution {
    public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if (j + 1 < i - 1) {
                        dp[j][i] = dp[j + 1][i - 1];
                    } else {
                        dp[j][i] = true;
                    }
                    if (dp[j][i]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
/**
 * dp[i][j] 表示s[i, i+1, i+2 ... j]是回文串
 * 如果dp[i][j]是true, 如果s[i - 1] == s[j + 1], 则dp[i - 1][j + 1] = true;
 * 所以思路就是先求小区间是否是回文，然后慢慢根据小区间判断大区间
 * 两层循环，第一层枚举长度，长度从1开始，第二层循环是起点i,然后判断s[i] 与s[i + len]的关系
 *
class Solution {
    public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<vector<bool> > dp(n, vector<bool>(n));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        cnt += n;
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (s[i] == s[j]) {
                    dp[i][j] = is_huiwen(i + 1, j - 1, dp);
                    if (dp[i][j]) {
                        cnt++;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return cnt;
    }

    bool is_huiwen(int i, int j, vector<vector<bool> > &dp) {
        if (i >= j) {
            return true;
        } else {
            return dp[i][j];
        }
    }
};
*/

/**
 * 思路二：
 * 枚举中心，由中心向两遍进行扩展，对于奇数和偶数扩展方式不同
 * 对于奇数s[i-j ... i ... i+j], 中心是s[i]
 * 对于偶数s[i-j-1 ... i ... i+j],中心是s[i-1,i]或者s[i-j ... i ... i+j+1]中心是s[i,i+1]
class Solution {
    public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n; j++) {
                if (s[i - j] == s[i + j]) {
                    res++;
                } else {
                //如果有一个不相等，就没必要继续扩展了
                    break;
                }
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
                if (s[i - j] == s[i + j + 1]) {
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
*/

int main() {
    return 0;
}
