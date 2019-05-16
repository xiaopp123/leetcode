#include "heads.h"
using namespace std;

public class Solution {
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    public String minWindow(String S, String T) {
        int n = S.length();
        int m = T.length();
        vector<<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int min_len = n;
        int start = -1;
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                if (S[i] == T[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            if (dp[i][m] != -1) {
                int len = i - dp[i][m];
                if (min_len > len) {
                    min_len = len;
                    start = dp[i][m];
                }
            }
        }
        if (start == -1) {
            return "";
        } else {
            return S.substr(start, min_len);
        }
    }
}

int main() {

    return 0;
}
