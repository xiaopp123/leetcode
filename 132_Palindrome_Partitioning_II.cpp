#include "heads.h"
using namespace std;

class Solution {
    public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n);
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i] = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if (j + 1 < i - 1) {
                        if (flag[j + 1][i - 1]) {
                            if (j == 0) {
                                dp[i] = 0;
                            } else {
                                dp[i] = min(dp[i], dp[j - 1] + 1);
                            }
                            flag[j][i] = flag[j + 1][i - 1];
                        }
                    } else {
                            if (j == 0) {
                                dp[i] = 0;
                            } else {
                                dp[i] = min(dp[i], dp[j - 1] + 1);
                            }
                            flag[j][i] = true;
                        }
                }
            }
        }
        return dp[n - 1];
    }
};


int main() {
    Solution* solution = new Solution();
    string s = "aab";
    solution->minCut(s);

    return 0;
}
