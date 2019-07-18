#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iostream>
#include "heads.h"
using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        for (int i = 0; i < len; i++) {
            if (s[i] == ')') {
                if (i - 1 >= 0 && dp[i - 1] > 0) {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                } else if (i - 1 >= 0 && s[i - 1] == '(') {
                    dp[i] = 2 + (i - 2 >= 0 ? dp[i - 2] : 0);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            res = max(dp[i], res);
        }
        return res;
    }
};

/*
class Solution {
    public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        int dp[len];
        memset(dp, 0, sizeof(dp));
        int maxRes = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(' ){
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }
                maxRes = max(maxRes, dp[i]);
            }
        }

        return maxRes;
    }
};

class Solution {
    public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int last = -1;
        stack<int> st;
        int maxLen = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    last = i;
                } else {
                    st.pop();
                    if (st.empty()) {
                        maxLen = max(maxLen, i - last);
                    } else {
                        maxLen = max(maxLen, i - st.top());
                    }
                }
            }
        }
        return maxLen;
    }
};
*/
int main() {

    return 0;
}
