#include "heads.h"
using namespace std;

class Solution {
    public:
    vector<vector<string>> partition(string s) {
        /*
        vector<vector<string>> res;
        vector<string> item;
        dfs(s, 0, item, res);
        */
        int n = s.length();
        int res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j]) {
                    if (i + 1 < j - 1) {
                        dp[i][j] = dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }

    int dfs(string s, int start, vector<string>& item, vector<vector<string>>& res) {
        if (start == (int)s.length()) {
            res.push_back(item);
            return 0;
        }
        for (int i = start; i < (int)s.length(); i++) {
            if (!is_palindrom(s, start, i)) {
                continue;
            }
            item.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, item, res);
            item.pop_back();
        }

        return 0;
    }

    bool is_palindrom(string s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start == end;
    }
};

int main() {
    return 0;
}
