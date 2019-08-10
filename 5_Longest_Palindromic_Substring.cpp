#include "heads.h"
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return s;
        }
        int start = 0;
        int max_len = 1;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
            dp[i][i] = true;
        }
        for (int len = 2; len < n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len;
                if (j < n && s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    start = i;
                    max_len = len;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

class Solution {
    public:
    string longestPalindrome(string s) {
        /**
         * 1.brute force
         * 2.枚举中心点: 奇数长度或者偶数长度
         * 3.动态规划
         * 4.O(n)算法
         */
        /*
        int n = s.length();
        int len = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int tempLen = 1 + 2 * getLengthOfPalindrome(i - 1, i + 1, s, n);
            if (len < tempLen) {
                len = tempLen;
                start = i - 1;
            }
            if (i < n - 1 && s[i] == s[i + 1]) {
                tempLen = 2 * getLengthOfPalindrome(i, i + 1, s, n);
                if (len < tempLen) {
                    len = tempLen;
                    start = i;
                }
            }
        }
        string res;
        start = start - len / 2 + 1;

        for (int i = 0; i < len; i++) {
            res += s[start + i];
        }

        return res;
        */
        int len = s.length();
        bool p[len][len];
        memset(p, false, sizeof(p));
        for (int i = 0; i < len; i++) {
            p[i][i] = true;
            if (i + 1 < len && s[i] == s[i + 1]) {
                p[i][i + 1] = true;
            }
        }
        int maxLen = 0;
        int start = 0;
        for (int j = 0; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (i + 1 < j - 1 && i + 1 < len && s[i] == s[j])
                    p[i][j] = p[i + 1][j - 1];
                    if (j - i + 1 < maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
            }
        }
        string res;
        for (int i = start; i < maxLen; i++) {
            res += s[i];
        }

        return res;
    }

    int getLengthOfPalindrome(int start, int end, string s, int n) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (start - i < 0 || end + i >= n) {
                break;
            }
            if (s[start - i] == s[end + i]) {
                len++;
            } else {
                break;
            }
        }

        return len;
    }
};
int main() {
    Solution* solution = new Solution();
    string s;
    while (cin >> s) {
        cout << solution->longestPalindrome(s) << endl;
    }
    return 0;
}
