#include "heads.h"
using namespace std;

class Solution {
    public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                dp[i + 1] += dp[i];
            }
            if (i - 1 >= 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] >= '0' || s[i] <= '6')))) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[len];
    }
};

int main() {
    Solution* solution = new Solution();
    string s;
    cin >> s;
    cout << solution->numDecodings(s) << endl;

}
