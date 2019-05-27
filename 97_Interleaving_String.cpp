#include "heads.h"
using namespace std;

/*
class Solution {
    public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) {
            return false;
        }
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < len1 + 1; i++) {
            dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);
        }
        for (int j = 1; j < len2 + 1; j++) {
            dp[0][j] = dp[0][j - 1] && (s3[j - 1] == s2[j - 1]);
        }

        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                dp[i][j] = (dp[i - 1][j] && (s3[i - 1 + j] == s1[i - 1])) || \
                           (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1]));
            }
        }

        return dp[len1][len2];
    }
};
*/

//递归的优化
class Solution {
    public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        set<pair<int, int>> s;
        return helper(s1, 0, s2, 0, s3, 0, s);
    }
    bool helper(string& s1, int i, string& s2, int j, string& s3, int k, set<pair<int,int>>& s) {
        //根据i和j编码
        //int key = i * s3.size() + j;
        pair<int, int> ij;
        ij.first = i;
        ij.second = j;
        if (s.count(ij)) {
            return false;
        }
        if (i == (int)s1.size()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == (int)s2.size()) {
            return s1.substr(i) == s3.substr(k);
        }
        bool flag1 = false;
        bool flag2 = false;
        if (s1[i] == s3[k]) {
            flag1 = helper(s1, i + 1, s2, j, s3, k + 1, s);
        }
        if (s2[j] == s3[k]) {
            flag2 = helper(s1, i, s2, j + 1, s3, k + 1, s);
        }
        s.insert(ij);
        return flag1 || flag2;
    }
};

/*
class Solution {
    public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() == 0) {
            return s1.length() == 0 && s2.length() == 0;
        }
        if (s3[0] != s1[0] && s3[0] != s2[0]) {
            return false;
        }
        bool flag1 = false;
        bool flag2 = false;
        if (s1.length() > 0 && s3[0] == s1[0]) {
            flag1 = isInterleave(s1.substr(1), s2, s3.substr(1));
        }
        if (s2.length() > 0 && s3[0] == s2[0]) {
            flag2 = isInterleave(s1, s2.substr(1), s3.substr(1));
        }

        return flag1 || flag2;
    }
};
*/

int main() {

    return 0;
}
