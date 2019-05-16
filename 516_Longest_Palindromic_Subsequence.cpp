#include "heads.h"
using namespace std;

class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int l = 1; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = l + i;
                if (s[i] == s[j]) {
                    if (i + 2 <= j) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = 2;
                    }
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {

    return 0;
}
