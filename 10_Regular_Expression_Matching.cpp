#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

/**
 * 递归版

class Solution {
    public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }
        //如果len(s) == 0, 虽然第一个位置没有配上，但有可能是继续匹配下去的，例如p = 'a*'
        bool firstMatch = (s.length() > 0) && (s[0] == p[0] || p[0] == '.');

        if (p.length() >= 2 && p[1] == '*') {
            //可以选择忽略掉第一个匹配上的字符, 或者直接继续匹配p
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));

        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};
*/
class Solution {
    public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        bool dp[lens + 1][lenp + 1];
        memset(dp, 0, sizeof(dp));
        //dp = new bool *[lens + 1];
        //for (int i = 0; i < lenp; i++) {
        //    dp[i] =  new bool[lenp + 1];
        //}

        dp[lens][lenp] = true;

        for (int i = lens; i >= 0; i--) {
            for (int j = lenp - 1; j >= 0; j--) {
                bool firstMatch = (i < lens) && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < lenp && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }

};

int main() {
    string s, p;
    Solution *solution = new Solution();
    while (cin >> s >> p) {
        cout << solution->isMatch(s, p) << endl;
    }
    return 0;
}
